#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/common.hpp>
#include <glm/ext.hpp>
#include <glm/vec4.hpp>

#include <memory>

#include "texture.h"

class Camera;

class OpenGLRenderer
{
  public:
    OpenGLRenderer();

    void draw(const Camera &camera);

  private:
    void drawTile(int worldX, int worldY, float width, float height);

    GLuint vertexBufferObject;
    GLuint vertexArrayObject;
    GLuint elementBufferObject;
    GLuint shaderProgram;
    GLuint modelId;
    GLuint projectionId;

    std::unique_ptr<Texture> texture;
};
