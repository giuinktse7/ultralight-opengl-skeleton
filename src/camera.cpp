#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include "log.h"

Camera::Camera(uint32_t width, uint32_t height)
    : Camera(-static_cast<int>(width) / 2, width / 2, height / 2, -static_cast<int>(height) / 2)
{
    setViewport(width, height);
}

Camera::Camera(float left, float right, float bottom, float top)
    : projection(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), view(1.0f), pos(0.0f)
{
    projectionView = projection * view;
}

Camera::Camera()
    : Camera(-400.0f, 400.0f, 300.0f, -300.0f)
{
}

void Camera::recalculateOrtho()
{
    auto dx = (float)_viewport.width / 2;
    auto dy = (float)_viewport.height / 2;

    projection = glm::ortho(-dx, dx, dy, -dy, -1.0f, 1.0f);

    recalculateViewMatrix();
}

void Camera::setViewport(uint32_t width, uint32_t height)
{
    if (width == _viewport.width && height == _viewport.height)
    {
        return;
    }

    _viewport = {width, height};

    recalculateOrtho();
}

void Camera::setWorldPos(int x, int y)
{
    pos.x = static_cast<float>(x);
    pos.y = static_cast<float>(y);

    recalculateViewMatrix();
}

void Camera::move(int dx, int dy)
{
    pos.x += dx;
    pos.y += dy;

    recalculateViewMatrix();
}

void Camera::recalculateViewMatrix()
{
    view = glm::translate(glm::mat4(1.0f), glm::vec3(-pos, 0.0f));

    projectionView = projection * view;
}
