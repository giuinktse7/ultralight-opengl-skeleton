#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>

class Camera
{
  public:
    Camera(uint32_t width, uint32_t height);
    Camera(float left, float right, float bottom, float top);
    Camera();

    void setWorldPos(int x, int y);
    void move(int dx, int dy);

    void setViewport(uint32_t width, uint32_t height);

    const glm::mat4 &projectionMatrix() const noexcept
    {
        return projection;
    }

    const glm::mat4 &viewProjectionMatrix() const noexcept
    {
        return projectionView;
    }

  private:
    void recalculateViewMatrix();
    void recalculateOrtho();

    struct
    {
        uint32_t width;
        uint32_t height;
    } _viewport = {0, 0};

    struct
    {
        uint32_t left;
        uint32_t right;
        uint32_t bottom;
        uint32_t top;
    } orthoParams = {0, 0, 0, 0};

    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 projectionView;

    // We only use x and y component
    glm::vec2 pos;

    // Floor stored separately
    int floor;
};