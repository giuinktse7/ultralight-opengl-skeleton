#pragma once

#include <filesystem>
#include <string>

class File
{
  public:
    static std::string readIntoString(const std::filesystem::path &path);
    static std::string readIntoString(const char *path);
    static std::string readIntoString(const std::string &path);
};