#pragma once

#include "camera.h"
#include "renderer.h"
#include "ultralight/js_event.h"

class OpenGLWindow
{
  public:
    OpenGLWindow(uint32_t width, uint32_t height);

    void moveCamera(int dx, int dy);

    void zoomIn();
    void zoomOut();

    void onMouseEvent(JSEvent::MouseEvent event);
    void onKeyboardEvent(JSEvent::KeyboardEvent event);

    void resize(uint32_t width, uint32_t height);

    void draw();

  private:
    OpenGLRenderer renderer;

    struct
    {
        int x;
        int y;
    } openGLAreaMousePos;

    struct
    {
        int x;
        int y;
    } windowMousePos;

    Camera camera;
};