#include "renderer.h"

#include <iostream>

#include "camera.h"
#include "file.h"

float vertices[] = {
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // top right
    1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
    0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f  // top left
};

unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

OpenGLRenderer::OpenGLRenderer()
{
    glGenBuffers(1, &vertexBufferObject);

    // Vertex shader
    uint32_t vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    auto vertexShaderSource = File::readIntoString("assets/shaders/shader.vert");
    auto vertexShaderSourcePtr = vertexShaderSource.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSourcePtr, NULL);
    glCompileShader(vertexShader);

    {
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
    }

    // Fragment shader unsigned int fragmentShader;
    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    auto fragmentShaderSource = File::readIntoString("assets/shaders/shader.frag");
    auto fragmentShaderSourcePtr = fragmentShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSourcePtr, NULL);
    glCompileShader(fragmentShader);

    {
        int success;
        char infoLog[512];
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
    }

    // Shader program
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    {
        int success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    modelId = glGetUniformLocation(shaderProgram, "model");
    projectionId = glGetUniformLocation(shaderProgram, "projection");

    glGenBuffers(1, &elementBufferObject);

    // Generate a VAO
    glGenVertexArrays(1, &vertexArrayObject);

    // 1. bind Vertex Array Object
    glBindVertexArray(vertexArrayObject);

    // 2. copy the vertices array into a buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. Copy the vertex index array into an EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 4. then set the vertex attributes pointers
    // Position & Texture
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void *)(4 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // 5. Unbind the buffers
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    auto texture = Texture::fromFile("assets/tile.png");
    this->texture = std::make_unique<Texture>(std::move(texture));
}

void OpenGLRenderer::draw(const Camera &camera)
{
    auto transform = camera.viewProjectionMatrix();

    glBindTexture(GL_TEXTURE_2D, texture->textureId());
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(projectionId, 1, GL_FALSE, &transform[0][0]);

    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            drawTile(x * 64, y * 64, 64.0f, 64.0f);
        }
    }

    glBindVertexArray(0);
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void OpenGLRenderer::drawTile(int worldPosX, int worldPosY, float width, float height)
{
    // TODO Optimize
    auto model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(worldPosX, worldPosY, 0.0f));
    model = glm::scale(model, glm::vec3(width, height, 1.0f));

    glUniformMatrix4fv(modelId, 1, GL_FALSE, &model[0][0]);

    glBindVertexArray(vertexArrayObject);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
