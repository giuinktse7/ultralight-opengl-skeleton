#pragma once

#include <AppCore/JSHelpers.h>
#include <optional>
#include <sstream>

#include "util.h"

namespace JSUtils
{
    using namespace ultralight;

    inline std::string JSStringToStdString(JSStringRef jsString)
    {
        size_t maxBufferSize = JSStringGetMaximumUTF8CStringSize(jsString);
        char *utf8Buffer = new char[maxBufferSize];
        size_t bytesWritten = JSStringGetUTF8CString(jsString, utf8Buffer, maxBufferSize);
        std::string utf_string = std::string(utf8Buffer, bytesWritten - 1); // the last byte is a null \0 which std::string doesn't need.
        delete[] utf8Buffer;
        return utf_string;
    }

    inline std::string showJSValue(const JSValue &value)
    {
        if (value.IsObject())
        {
            return "object";
        }
        else if (value.IsArray())
        {
            return "array";
        }
        else if (value.IsString())
        {
            return JSUtils::JSStringToStdString(value.ToString());
        }
        else if (value.IsNumber())
        {
            return std::to_string(value.ToNumber());
        }
        else if (value.IsFunction())
        {
            return "function";
        }
        else if (value.IsUndefined())
        {
            return "undefined";
        }
        else if (value.IsNull())
        {
            return "null";
        }
        else if (value.IsBoolean())
        {
            return std::to_string(value.ToBoolean());
        }
        else
        {
            return "unknown";
        }
    }

    inline std::string showJSArgs(const JSArgs &args)
    {
        std::vector<std::string> xs;
        std::ostringstream result;
        for (int i = 0; i < args.size(); ++i)
        {
            xs.push_back(showJSValue(args[i]));
        }

        return joinList(xs, ", ");
    }

    inline JSStringRef stringToJSString(const char *str)
    {
        return JSStringCreateWithUTF8CString(str);
    }

    inline JSStringRef stringToJSString(std::string str)
    {
        return JSStringCreateWithUTF8CString(str.c_str());
    }

    inline std::optional<double> getDouble(const JSObject &jsObject, const JSStringRef propertyName)
    {
        if (!jsObject.HasProperty(propertyName))
        {
            return std::nullopt;
        }

        auto result = jsObject[propertyName];
        if (result.IsNumber())
        {
            return result.ToNumber();
        }
        else
        {
            return std::nullopt;
        }
    }

    inline std::optional<double> getDouble(const JSValue &jsValue, const JSStringRef propertyName)
    {
        if (!jsValue.IsObject())
        {
            return std::nullopt;
        }

        auto jsObject = jsValue.ToObject();
        return getDouble(jsObject, propertyName);
    }

    inline std::optional<int> getInt(const JSObject &jsObject, const JSStringRef propertyName)
    {
        const auto value = getDouble(jsObject, propertyName);
        if (!value)
        {
            return std::nullopt;
        }

        double intpart;
        if (modf(*value, &intpart) == 0.0)
        {
            return static_cast<int>(intpart);
        }
        else
        {
            return std::nullopt;
        }
    }

    inline std::optional<int> getInt(const JSValue &jsValue, const JSStringRef propertyName)
    {
        if (!jsValue.IsObject())
        {
            return std::nullopt;
        }

        auto jsObject = jsValue.ToObject();
        return getInt(jsObject, propertyName);
    }

    inline std::optional<std::string> getString(const JSObject &jsObject, const JSStringRef propertyName)
    {
        if (!jsObject.HasProperty(propertyName))
        {
            return std::nullopt;
        }

        auto result = jsObject[propertyName];
        if (result.IsString())
        {
            return JSStringToStdString(result.ToString());
        }
        else
        {
            return std::nullopt;
        }
    }

    inline std::optional<std::string> getString(const JSValue &jsValue, const JSStringRef propertyName)
    {
        if (!jsValue.IsObject())
        {
            return std::nullopt;
        }

        auto jsObject = jsValue.ToObject();
        return getString(jsObject, propertyName);
    }

    inline std::optional<bool> getBool(const JSObject &jsObject, const JSStringRef propertyName)
    {
        if (!jsObject.HasProperty(propertyName))
        {
            return std::nullopt;
        }

        auto result = jsObject[propertyName];
        if (result.IsBoolean())
        {
            return result.ToBoolean();
        }
        else
        {
            return std::nullopt;
        }
    }

    inline std::optional<bool> getBool(const JSValue &jsValue, const JSStringRef propertyName)
    {
        if (!jsValue.IsObject())
        {
            return std::nullopt;
        }

        auto jsObject = jsValue.ToObject();
        return getBool(jsObject, propertyName);
    }

    inline std::optional<double> getDouble(const JSValue &jsValue, const char *propertyName)
    {
        return getDouble(jsValue, stringToJSString(propertyName));
    }

    inline std::optional<double> getDouble(const JSObject &jsObject, const char *propertyName)
    {
        return getDouble(jsObject, stringToJSString(propertyName));
    }

    inline std::optional<std::string> getString(const JSValue &jsValue, const char *propertyName)
    {
        return getString(jsValue, stringToJSString(propertyName));
    }

    inline std::optional<std::string> getString(const JSObject &jsObject, const char *propertyName)
    {
        return getString(jsObject, stringToJSString(propertyName));
    }

    inline std::optional<bool> getBool(const JSValue &jsValue, const char *propertyName)
    {
        return getBool(jsValue, stringToJSString(propertyName));
    }

    inline std::optional<bool> getBool(const JSObject &jsObject, const char *propertyName)
    {
        return getBool(jsObject, stringToJSString(propertyName));
    }

    inline std::optional<int> getInt(const JSValue &jsValue, const char *propertyName)
    {
        return getInt(jsValue, stringToJSString(propertyName));
    }

    inline std::optional<int> getInt(const JSObject &jsObject, const char *propertyName)
    {
        return getInt(jsObject, stringToJSString(propertyName));
    }

} // namespace JSUtils