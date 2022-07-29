#include "app.h"

#include "gl_texture_surface.h"
#include "log.h"
#include "opengl_window.h"
#include "show_datatype.h"
#include "texture.h"
#include "ultralight/js_event.h"
#include "ultralight/js_utils.h"
#include "web_tile.h"
#include <AppCore/App.h>
#include <AppCore/Platform.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <math.h>
#include <spdlog/spdlog.h>
#include <sstream>
#include <string>
#include <thread>

extern "C"
{

    // Called by GLFW when an error is encountered.
    static void glfwErrorCallback(int error, const char *description)
    {
        fprintf(stderr, "GLFW Error: %s\n", description);
    }
}

void MainApp::framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
    draw();
}

MainApp::MainApp()
{
    App::Create();
    glfwSetErrorCallback(glfwErrorCallback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int monitorWidth = mode->width;
    int monitorHeight = mode->height;

    width_ = static_cast<int>(monitorWidth * 0.8);
    height_ = static_cast<int>(monitorHeight * 0.8);

    if (width_ > 1920)
    {
        width_ = 1920;
    }

    window_.reset(new AppWindow(width_, height_, false));
    window_->MoveToCenter();
    window_->setListener(this);
    window_->SetTitle("Ultralight OpenGL Skeleton");

    width_ = window_->width();
    height_ = window_->height();

    Config config;
    config.scroll_timer_delay = 1.0 / (mode->refreshRate);
    config.animation_timer_delay = 1.0 / (mode->refreshRate);

    /// Pass our configuration to the Platform singleton so that the library
    /// can use it.
    ///
    /// The Platform singleton can be used to define various platform-specific
    /// properties and handlers such as file system access, font loaders, and
    /// the gpu driver.
    Platform::instance().set_config(config);

    /// Use AppCore's font loader singleton to load fonts from the OS.
    /// You could replace this with your own to provide your own fonts.
    Platform::instance().set_font_loader(GetPlatformFontLoader());

    /// Use AppCore's file system singleton to load file:/// URLs from the OS.
    ///
    /// You could replace this with your own to provide your own file loader
    /// (useful if you need to bundle encrypted / compressed HTML assets).
    Platform::instance().set_file_system(GetPlatformFileSystem("./assets"));

    /// Register our App instance as a logger so we can handle the
    /// library's LogMessage() event below in case we encounter an error.
    Platform::instance().set_logger(this);

    // If CPU-rendered UI performance is not enough, try GPU rendered.
    // in web_tile.cpp: view_config.is_accelerated = true;
    // Then figure out how to use GPU driver, unclear how to though. Resources to investigate:
    // https://docs.ultralig.ht/docs/using-a-custom-gpudriver
    // https://github.com/ultralight-ux/AppCore/tree/master/src/linux
    // https://github.com/ultralight-ux/AppCore/blob/master/src/linux/WindowGLFW.cpp#L344
    // gpu_context_.reset(new GPUContextGL(true, false));
    // Platform::instance().set_gpu_driver(gpu_context_->driver());

    /// Use a custom factory to create Surfaces backed by an OpenGL texture.
    surface_factory_.reset(new GLTextureSurfaceFactory());
    Platform::instance().set_surface_factory(surface_factory_.get());

    /// Create our Renderer (you should only create this once per application).
    ///
    /// The Renderer singleton maintains the lifetime of the library and
    /// is required before creating any Views. It should outlive any Views.
    ///
    /// You should set up the Platform singleton before creating this.
    renderer_ = Renderer::Create();

    // create UI
    uiTile = std::make_unique<WebTile>(renderer_, width_, height_, window_->scale());

    uiTile->view()->LoadURL("file:///index.html");
    uiTile->view()->set_view_listener(this);
    uiTile->view()->set_load_listener(this);

    overlayUI = std::make_unique<OverlayUI>(std::move(uiTile), width_, height_);
    overlayUI->init();

    openGLWindow = std::make_unique<OpenGLWindow>(width_, height_);
}

MainApp::~MainApp()
{
    renderer_ = nullptr;

    glfwTerminate();
}

void MainApp::run()
{
    /// Our main run loop tries to conserve CPU usage by sleeping in 4ms bursts
    /// between each paint.
    ///
    /// We use glfwWaitEventsTimeout() to perform the sleep, which also allows
    /// us the ability to wake up early if the OS sends us an event.
    std::chrono::milliseconds intervalMs(4);
    std::chrono::steady_clock::time_point next_paint = std::chrono::steady_clock::now();

    while (!glfwWindowShouldClose(window_->handle()))
    {
        /// Query the system clock to see how many milliseconds are left until the next scheduled paint.
        long long timeoutMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                                  next_paint - std::chrono::steady_clock::now())
                                  .count();
        unsigned long timeout = timeoutMs <= 0 ? 0 : (unsigned long)timeoutMs;

        /// Use glfwWaitEventsTimeout() if we still have time left before the next paint.
        /// (Will use OS primitives to sleep and wait for OS input events)
        ///
        /// Otherwise, call glfwPollEvents() immediately and continue.
        if (timeout > 0)
        {
            glfwWaitEventsTimeout(timeout / 1000.0);
        }
        else
        {
            glfwPollEvents();
        }

        /// Allow Ultralight to update internal timers, JavaScript callbacks, and other resource callbacks.
        renderer_->Update();

        if (should_quit_)
            return;

        /// Update our timeout by querying the system clock again.
        auto dt = next_paint - std::chrono::steady_clock::now();
        timeoutMs = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();

        /// Perform paint if we have reached the scheduled time.
        if (timeoutMs <= 0)
        {
            draw();

            /// Schedule the next paint.
            next_paint = std::chrono::steady_clock::now() + intervalMs;
        }
    }
}

void MainApp::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    renderer_->Render();

    openGLWindow->draw();
    overlayUI->draw();

    window_->PresentFrame();
}

void MainApp::onClose()
{
    should_quit_ = true;
}

void MainApp::onResize(uint32_t width, uint32_t height)
{
    if (width == width_ && height == height_)
        return;

    overlayUI->resize(width, height);
    openGLWindow->resize(width, height);

    width_ = width;
    height_ = height;

    glViewport(0, 0, width_, height_);
    draw();
}

void MainApp::onChangeFocus(bool focused)
{
}

void MainApp::onKeyEvent(const KeyEvent &event)
{
    overlayUI->onKeyEvent(event);
}

void MainApp::onMouseEvent(const MouseEvent &event)
{
    if (event.type != MouseEvent::Type::kType_MouseMoved)
    {
        auto eventType = event.type == MouseEvent::Type::kType_MouseDown ? "mousedown" : "mouseup";
        console::log("{}", eventType);
    }

    overlayUI->onMouseEvent(event);
}

void MainApp::onScrollEvent(const ScrollEvent &event)
{
    overlayUI->onScrollEvent(event);
}

void MainApp::OnChangeCursor(ultralight::View *caller,
                             Cursor cursor)
{
    window_->SetCursor(cursor);
}

void MainApp::OnFailLoading(ultralight::View *caller,
                            uint64_t frame_id,
                            bool is_main_frame,
                            const String &url,
                            const String &description,
                            const String &error_domain,
                            int error_code)
{
}

void MainApp::LogMessage(LogLevel log_level,
                         const String &message)
{
    String msg(message);
    std::cout << msg.utf8().data() << std::endl;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>JS Logging>>>>>>>>>>>>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>

//
// Inherited from ViewListener::OnAddConsoleMessage
//
//
void MainApp::OnAddConsoleMessage(View *caller, MessageSource source, MessageLevel level, const String &message, uint32_t lineNumber, uint32_t columnNumber, const String &sourceId)
{

    std::cout << "[Console]: [" << source << "] [" << level << "] " << ultralightToUtf8(message);

    if (source == kMessageSource_JS)
    {
        std::cout << " (" << ultralightToUtf8(sourceId) << " @ line " << lineNumber
                  << ", col " << columnNumber << ")";
    }

    std::cout << std::endl;
}

// Use LoadListener::OnDOMReady to wait for the DOM to load.
void MainApp::OnDOMReady(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const String &url)
{
    // For the UI view
    auto view = overlayUI->ui->view();
    RefPtr<JSContext> locked_context = caller->LockJSContext();
    SetJSContext(locked_context->ctx());

    JSObject global = JSGlobalObject();

    global["onGLKeyEvent"] = BindJSCallback(&MainApp::onGLKeyEvent);
    global["onGLWheelEvent"] = BindJSCallback(&MainApp::onGLWheelEvent);
    global["onGLMouseEvent"] = BindJSCallback(&MainApp::onGLMouseEvent);
}

void MainApp::onGLKeyEvent(const JSObject &obj, const JSArgs &args)
{
#ifdef _DEBUG
    if (args.size() != 1)
    {
        auto argList = JSUtils::showJSArgs(args);
        console::error("[onGLKeyEvent] Expected arguments (event: KeyboardEvent). Received {} args: {}", args.size(), argList);
        exit(EXIT_FAILURE);
    }

    if (!args[0].IsObject())
    {
        console::error("[onGLKeyEvent] Expected first argument (event: KeyboardEvent) to be of type KeyboardEvent, but received {}", JSUtils::showJSValue(args[0]));
        exit(EXIT_FAILURE);
    }

    // https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent
    auto event = args[0].ToObject();

    auto keycode = JSUtils::getInt(event, "keyCode");
    auto ctrlKey = JSUtils::getBool(event, "ctrlKey");
    auto shiftKey = JSUtils::getBool(event, "shiftKey");
    auto altKey = JSUtils::getBool(event, "altKey");
    auto metaKey = JSUtils::getBool(event, "metaKey");
    auto repeat = JSUtils::getBool(event, "repeat");

    if (keycode && ctrlKey && shiftKey && altKey && metaKey && repeat)
    {
        auto keyboardEvent = JSEvent::KeyboardEvent{
            .keycode = static_cast<JSEvent::KeyCode>(*keycode),
            .ctrlKey = *ctrlKey,
            .shiftKey = *shiftKey,
            .altKey = *altKey,
            .repeat = *repeat,
            .metaKey = *metaKey};

        openGLWindow->onKeyboardEvent(keyboardEvent);
    }
    else
    {
        console::error("[onGLKeyEvent] Missing one or more parameters.");
        exit(EXIT_FAILURE);
    }
#else
    auto event = args[0].ToObject();
    auto keyboardEvent = JSEvent::KeyboardEvent{
        .keycode = static_cast<JSEvent::KeyCode>(event["keyCode"].ToNumber()),
        .ctrlKey = event["ctrlKey"].ToBoolean(),
        .shiftKey = event["shiftKey"].ToBoolean(),
        .altKey = event["altKey"].ToBoolean(),
        .repeat = event["repeat"].ToBoolean(),
        .metaKey = event["metaKey"].ToBoolean()};

    openGLWindow->onKeyboardEvent(keyboardEvent);
#endif
}

/**
 * 
 * @param obj the `this` JS object
 * @param args Expects two argument:
 *      - deltaX: number
 *      - deltaY: number
 */
void MainApp::onGLWheelEvent(const JSObject &obj, const JSArgs &args)
{
    if (args.size() != 2)
    {
        auto argList = JSUtils::showJSArgs(args);
        console::error("[onGLWheelEvent] Expected arguments (deltaX: number, deltaY: number). Received {} args: {}", args.size(), argList);
        exit(EXIT_FAILURE);
    }

    if (!args[0].IsNumber())
    {
        console::error("[onGLWheelEvent] Expected first argument (deltaX) to be number, but received {}.", JSUtils::showJSValue(args[0]));
    }

    if (!args[1].IsNumber())
    {
        console::error("[onGLWheelEvent] Expected first argument (deltaX) to be number, but received {}.", JSUtils::showJSValue(args[1]));
    }

    double deltaX = args[0].ToNumber();
    double deltaY = args[1].ToNumber();

    // TODO Take different zoom values into account
    if (abs(deltaY) >= std::numeric_limits<double>::epsilon())
    {
        if (util::sgn(deltaY) == 1)
        {
            openGLWindow->zoomOut();
        }
        else
        {
            openGLWindow->zoomIn();
        }
    }
}

void MainApp::onGLMouseEvent(const JSObject &obj, const JSArgs &args)
{
// Only check mouse events in debug mode
#ifdef _DEBUG
    if (args.size() != 1)
    {
        auto argList = JSUtils::showJSArgs(args);
        console::error("[onGLMouseEvent] Expected arguments (event: MouseEvent). Received {} args: {}", args.size(), argList);
        exit(EXIT_FAILURE);
    }

    if (!args[0].IsObject())
    {
        console::error("[onGLMouseEvent] Expected first argument (event: MouseEvent) to be of type MouseEvent, but received {}", JSUtils::showJSValue(args[0]));
        exit(EXIT_FAILURE);
    }

    // https://developer.mozilla.org/en-US/docs/Web/API/MouseEvent
    auto event = args[0].ToObject();

    auto offsetX = JSUtils::getDouble(event, "offsetX");
    auto offsetY = JSUtils::getDouble(event, "offsetY");

    auto clientX = JSUtils::getDouble(event, "clientX");
    auto clientY = JSUtils::getDouble(event, "clientY");

    if (offsetX && offsetY && clientX && clientY)
    {
        JSEvent::MouseEvent e;
        e.type = JSEvent::parseMouseEventType(event);
        e.offsetX = static_cast<uint32_t>(*offsetX);
        e.offsetY = static_cast<uint32_t>(*offsetY);
        e.clientX = static_cast<uint32_t>(*clientX);
        e.clientY = static_cast<uint32_t>(*clientY);
        openGLWindow->onMouseEvent(e);
    }
    else
    {
        console::error("[onGLMouseEvent] Could not get required keys from the JS event object.");
        exit(EXIT_FAILURE);
    }
#else
    auto event = args[0].ToObject();

    JSEvent::MouseEvent e{
        .type = JSEvent::parseMouseEventType(event),
        .clientX = static_cast<uint32_t>(event["clientX"].ToNumber()),
        .clientY = static_cast<uint32_t>(event["clientY"].ToNumber()),
        .offsetX = static_cast<uint32_t>(event["offsetX"].ToNumber()),
        .offsetY = static_cast<uint32_t>(event["offsetY"].ToNumber())};
    openGLWindow->onMouseEvent(e);
#endif
}
