#include "overlay_ui.h"

#include <iostream>
#include <ostream>

#include "log.h"
#include "show_datatype.h"

// The vertices of our 3D quad
const GLfloat GVertices[] = {
    -1.0f,
    -1.0f,
    0.0f,
    1.0f,
    -1.0f,
    0.0f,
    -1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
};

// The UV texture coordinates of our 3D quad
const GLshort GTextures[] = {
    0,
    1,
    1,
    1,
    0,
    0,
    1,
    0,
};

OverlayUI::OverlayUI(std::unique_ptr<WebTile> &&ui, uint32_t screenWidth, uint32_t screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), ui(std::move(ui))
{
}

GLfloat triangleVertices[] = {
    -1, -1, 0,
    -1, 1, 0,
    1, 1, 0};

void OverlayUI::drawTile(std::unique_ptr<WebTile> &tile)
{
    GLTextureSurface *surface = tile->surface();
    if (surface)
    {
        int tileWidth = surface->width();
        int tileHeight = surface->height();

        glVertexPointer(3, GL_FLOAT, 0, GVertices);
        glEnableClientState(GL_VERTEX_ARRAY);
        glTexCoordPointer(2, GL_SHORT, 0, GTextures);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glBindTexture(GL_TEXTURE_2D, surface->GetTextureAndSyncIfNeeded());
        glColor4f(1, 1, 1, 1);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void OverlayUI::resize(uint32_t width, uint32_t height)
{
    screenWidth = width;
    screenHeight = height;

    ui->view()->Resize(width, height);
}

void OverlayUI::draw()
{
    drawTile(ui);
}

void OverlayUI::init()
{
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    // glClearColor(0.812f, 0.847f, 0.863f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    glClear(GL_COLOR_BUFFER_BIT);
}

void OverlayUI::onChangeFocus(bool focused)
{
}

void OverlayUI::onKeyEvent(const KeyEvent &event)
{
    // std::cout << event << std::endl;

    ui->view()->FireKeyEvent(event);
}

void OverlayUI::onMouseEvent(const MouseEvent &event)
{
    ui->view()->FireMouseEvent(event);
}

void OverlayUI::onScrollEvent(const ScrollEvent &event)
{
    ui->view()->FireScrollEvent(event);
}
