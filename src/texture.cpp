#include "texture.h"

#include <format>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"

Texture::Texture(uint32_t width, uint32_t height, uint32_t channelCount, std::vector<byte> &&data, bool generateMipmap)
    : width(width), height(height), channelCount(channelCount), data(std::move(data))
{
    glGenTextures(1, &_textureId);
    glBindTexture(GL_TEXTURE_2D, _textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    auto minFilter = generateMipmap ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->data.data());

    if (generateMipmap)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::Texture(uint32_t width, uint32_t height, uint32_t channelCount, unsigned char *buffer, bool generateMipmap)
    : Texture(width, height, channelCount, {buffer, buffer + width * height * channelCount}, generateMipmap)
{
}

Texture Texture::fromFile(const std::string &file)
{
    stbi_set_flip_vertically_on_load(true);
    int width, height, channelCount;
    unsigned char *data = stbi_load(file.c_str(), &width, &height, &channelCount, 0);

    if (!data)
    {
        std::cout << std::format("Failed to load texture from file: {}", file);
        exit(1);
    }

    return Texture(width, height, channelCount, data);
}

Texture::Texture(Texture &&other)
    : width(other.width),
      height(other.height),
      channelCount(other.channelCount),
      data(std::move(other.data)),
      _textureId(other._textureId)
{
    other.width = 0;
    other.height = 0;
    other.channelCount = 0;
    other._textureId = 0;
}
