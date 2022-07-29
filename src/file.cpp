#include "file.h"

#include <fstream>
#include <iostream>

std::string File::readIntoString(const std::string &path)
{

    // Open the stream to 'lock' the file.
    std::ifstream f(path, std::ios::in | std::ios::binary);

    // Obtain the size of the file.
    const auto sz = std::filesystem::file_size(path);

    // Create a buffer.
    std::string result(sz, '\0');

    // Read the whole file into the buffer.
    f.read(result.data(), sz);

    return result;
}

std::string File::readIntoString(const std::filesystem::path &path)
{
    return File::readIntoString(path.string());
}

std::string File::readIntoString(const char *path)
{
    return File::readIntoString(std::string(path));
}
