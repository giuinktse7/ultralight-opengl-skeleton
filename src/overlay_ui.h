
#pragma once

#include <memory>

#include "web_tile.h"

class OverlayUI
{
  public:
    OverlayUI(std::unique_ptr<WebTile> &&ui, uint32_t x, uint32_t y);

    void init();
    void draw();

    uint32_t screenWidth;
    uint32_t screenHeight;

    void onChangeFocus(bool focused);
    void onKeyEvent(const KeyEvent &event);
    void onMouseEvent(const MouseEvent &event);
    void onScrollEvent(const ScrollEvent &event);

    void resize(uint32_t width, uint32_t height);

    std::unique_ptr<WebTile> ui;

  private:
    void drawTile(std::unique_ptr<WebTile> &tile);

    GLfloat color_[16];
};