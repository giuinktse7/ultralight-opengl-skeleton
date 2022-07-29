#include "opengl_window.h"

#include "log.h"
#include "ultralight/js_event.h"

OpenGLWindow::OpenGLWindow(uint32_t width, uint32_t height)
    : renderer(), camera(width, height)
{
}

void OpenGLWindow::moveCamera(int dx, int dy)
{
    camera.move(dx, dy);
}

void OpenGLWindow::zoomIn()
{
    // TODO
}

void OpenGLWindow::zoomOut()
{
    // TODO
}

void OpenGLWindow::draw()
{
    renderer.draw(camera);
}

void OpenGLWindow::resize(uint32_t width, uint32_t height)
{
    camera.setViewport(width, height);
}

void OpenGLWindow::onMouseEvent(JSEvent::MouseEvent event)
{
    using JSEvent::MouseEventType;

    openGLAreaMousePos.x = event.offsetX;
    openGLAreaMousePos.y = event.offsetY;

    windowMousePos.x = event.clientX;
    windowMousePos.y = event.clientY;

    // console::log(event);
    // switch (event.type)
    // {
    //     case MouseEventType::MouseDown:
    //         break;
    // }
}

void OpenGLWindow::onKeyboardEvent(JSEvent::KeyboardEvent event)
{
    using JSEvent::KeyCode;
    console::debug(event);

    // Camera movement
    const int DELTA = 32;
    switch (event.keycode)
    {
        case KeyCode::ArrowLeft:
            moveCamera(-DELTA, 0);
            break;
        case KeyCode::ArrowRight:
            moveCamera(DELTA, 0);
            break;
        case KeyCode::ArrowDown:
            moveCamera(0, DELTA);
            break;
        case KeyCode::ArrowUp:
            moveCamera(0, -DELTA);
            break;
        default:
            break;
    }
}
