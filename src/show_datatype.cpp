#include "show_datatype.h"

#include <Ultralight/Ultralight.h>

std::ostream &operator<<(std::ostream &os, const ultralight::KeyEvent::Type &type)
{
    switch (type)
    {
        case ultralight::KeyEvent::Type::kType_Char:
            os << "kType_Char";
            break;
        case ultralight::KeyEvent::Type::kType_KeyUp:
            os << "kType_KeyUp";
            break;
        case ultralight::KeyEvent::Type::kType_KeyDown:
            os << "kType_KeyDown";
            break;
        case ultralight::KeyEvent::Type::kType_RawKeyDown:
            os << "kType_RawKeyDown";
            break;
        default:
            os << "Unknown key event";
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const ultralight::KeyEvent &event)
{
    os << "[" << event.type << "] " << event.text.utf8().data();
    return os;
}

std::ostream &operator<<(std::ostream &os, const ultralight::MessageSource &source)
{
    using ultralight::MessageSource;

    switch (source)
    {
        case MessageSource::kMessageSource_XML:
            os << "XML";
            break;
        case MessageSource::kMessageSource_JS:
            os << "JS";
            break;
        case MessageSource::kMessageSource_Network:
            os << "Network";
            break;
        case MessageSource::kMessageSource_ConsoleAPI:
            os << "ConsoleAPI";
            break;
        case MessageSource::kMessageSource_Storage:
            os << "Storage";
            break;
        case MessageSource::kMessageSource_AppCache:
            os << "AppCache";
            break;
        case MessageSource::kMessageSource_Rendering:
            os << "Rendering";
            break;
        case MessageSource::kMessageSource_CSS:
            os << "CSS";
            break;
        case MessageSource::kMessageSource_Security:
            os << "Security";
            break;
        case MessageSource::kMessageSource_ContentBlocker:
            os << "ContentBlocker";
            break;
        case MessageSource::kMessageSource_Other:
            os << "Other";
            break;
        default:
            break;
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const ultralight::MessageLevel &level)
{
    using ultralight::MessageLevel;

    switch (level)
    {
        case MessageLevel::kMessageLevel_Log:
            os << "Log";
            break;
        case MessageLevel::kMessageLevel_Warning:
            os << "Warning";
            break;
        case MessageLevel::kMessageLevel_Error:
            os << "Error";
            break;
        case MessageLevel::kMessageLevel_Debug:
            os << "Debug";
            break;
        case MessageLevel::kMessageLevel_Info:
            os << "Info";
            break;
        default:
            break;
    }

    return os;
}
