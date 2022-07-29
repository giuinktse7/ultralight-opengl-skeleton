#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <stdint.h>
#include <string>
#include <vector>

typedef unsigned char byte;

class Texture
{
  public:
    Texture(uint32_t width, uint32_t height, uint32_t channelCount, std::vector<byte> &&data, bool generateMipmap = false);
    Texture(uint32_t width, uint32_t height, uint32_t channelCount, unsigned char *buffer, bool generateMipmap = false);

    Texture(Texture &&other);

    static Texture fromFile(const std::string &file);

    void loadIntoGL();

    const uint32_t textureId() const noexcept
    {
        return _textureId;
    }

  private:
    uint32_t _textureId = 0;
    std::vector<byte> data;

    uint32_t width;
    uint32_t height;
    uint32_t channelCount;
};