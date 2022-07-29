#include "util.h"

#include <algorithm>

util::Size::Size(int width, int height)
    : w(width), h(height) {}

std::string util::unicodePath(std::filesystem::path path)
{
    return std::filesystem::absolute(path).string();
}

void to_lower_str(std::string &source)
{
    std::transform(source.begin(), source.end(), source.begin(), tolower);
}

void to_upper_str(std::string &source)
{
    std::transform(source.begin(), source.end(), source.begin(), toupper);
}

std::string as_lower_str(std::string s)
{
    to_lower_str(s);
    return s;
}

std::string joinList(std::vector<std::string> arr, std::string delimiter)
{
    if (arr.empty())
        return "";

    std::string result;
    for (auto i : arr)
        result += i + delimiter;
    result = result.substr(0, result.size() - delimiter.size());

    return result;
}