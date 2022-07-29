#pragma once

#include <ostream>

#include <Ultralight/KeyEvent.h>
#include <Ultralight/Listener.h>
#include <Ultralight/String.h>

std::ostream &operator<<(std::ostream &os, const ultralight::KeyEvent::Type &type);
std::ostream &operator<<(std::ostream &os, const ultralight::KeyEvent &event);

std::ostream &operator<<(std::ostream &os, const ultralight::MessageSource &source);
std::ostream &operator<<(std::ostream &os, const ultralight::MessageLevel &level);

inline std::string ultralightToUtf8(const ultralight::String &str)
{
    ultralight::String8 utf8 = str.utf8();
    return std::string(utf8.data(), utf8.length());
}
