#pragma once

#include "window.h"

#include "overlay_ui.h"

#include "ultralight/keycodes.h"
#include <AppCore/JSHelpers.h>
#include <Ultralight/platform/Logger.h>

#include <memory>
#include <string>
#include <vector>

class WebTile;
class OpenGLWindow;
struct GLFWwindow;
class GLTextureSurfaceFactory;

class MainApp : public WindowListener, public ViewListener, public LoadListener, public Logger
{
  public:
    MainApp();
    ~MainApp();

    void run();

    void draw();

    /////////////////////////////////////////////////////////////////////////////
    /// Inherited from WindowListener:                                        ///
    /////////////////////////////////////////////////////////////////////////////

    virtual void onClose() override;

    virtual void onResize(uint32_t width, uint32_t height) override;

    virtual void onChangeFocus(bool focused) override;

    virtual void onKeyEvent(const KeyEvent &evt) override;

    virtual void onMouseEvent(const MouseEvent &evt) override;

    virtual void onScrollEvent(const ScrollEvent &evt) override;

    /////////////////////////////////////////////////////////////////////////////
    /// Inherited from ViewListener:                                          ///
    /////////////////////////////////////////////////////////////////////////////

    virtual void OnAddConsoleMessage(View *caller, MessageSource source, MessageLevel level, const String &message, uint32_t lineNumber, uint32_t columnNumber, const String &sourceId) override;

    virtual void OnChangeCursor(ultralight::View *caller,
                                Cursor cursor) override;

    /////////////////////////////////////////////////////////////////////////////
    /// Inherited from LoadListener:                                          ///
    /////////////////////////////////////////////////////////////////////////////

    virtual void OnFailLoading(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const String &url, const String &description, const String &error_domain, int error_code) override;

    virtual void OnDOMReady(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const String &url) override;

    void onGLKeyEvent(const JSObject &obj, const JSArgs &args);
    void onGLWheelEvent(const JSObject &obj, const JSArgs &args);
    void onGLMouseEvent(const JSObject &obj, const JSArgs &args);

    /////////////////////////////////////////////////////////////////////////////
    /// Inherited from Logger:                                                ///
    /////////////////////////////////////////////////////////////////////////////

    virtual void LogMessage(LogLevel log_level,
                            const String &message) override;

    void framebufferSizeCallback(GLFWwindow *window, int width, int height);

    void CallbackFromJs(const JSObject &thisObject, const JSArgs &args);

  protected:
    int width_;
    int height_;
    bool should_quit_ = false;

    std::unique_ptr<WebTile> uiTile;
    std::unique_ptr<OpenGLWindow> openGLWindow;

    RefPtr<Renderer> renderer_;
    std::unique_ptr<GLTextureSurfaceFactory> surface_factory_;
    std::unique_ptr<AppWindow> window_;

    std::unique_ptr<OverlayUI> overlayUI;

    Keycodes::JSKeyMap jsKeymap = Keycodes::JSKeyMap();
};
