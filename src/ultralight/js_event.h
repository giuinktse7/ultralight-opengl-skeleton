#pragma once

#include "spdlog/fmt/ostr.h" // must be included
#include <AppCore/JSHelpers.h>
#include <ostream>
#include <stdint.h>
#include <string_view>

#include "js_utils.h"
#include "util.h"

#include "log.h"

namespace JSEvent
{
    enum class MouseEventType
    {
        DoubleClick, // dblclick
        MouseDown,   // mousedown
        MouseEnter,  // mouseenter
        MouseLeave,  // mouseleave
        MouseMove,   // mousemove
        MouseOut,    // mouseout
        MouseOver,   // mouseover
        MouseUp      // mouseup
    };

    inline MouseEventType parseMouseEventType(const ultralight::JSObject &object)
    {
        auto value = JSUtils::JSStringToStdString(object["type"].ToString());
        if (value == "dblclick")
        {
            return MouseEventType::DoubleClick;
        }
        else if (value == "mousedown")
        {
            return MouseEventType::MouseDown;
        }
        else if (value == "mouseenter")
        {
            return MouseEventType::MouseEnter;
        }
        else if (value == "mouseleave")
        {
            return MouseEventType::MouseLeave;
        }
        else if (value == "mousemove")
        {
            return MouseEventType::MouseMove;
        }
        else if (value == "mouseout")
        {
            return MouseEventType::MouseOut;
        }
        else if (value == "mouseover")
        {
            return MouseEventType::MouseOver;
        }
        else if (value == "mouseup")
        {
            return MouseEventType::MouseUp;
        }
        else
        {
            console::error("[parseMouseEventType] Unknown MouseEvent type: {}.", value);
            exit(EXIT_FAILURE);
        }
    }

    struct MouseEvent
    {
        MouseEventType type;

        bool ctrlKey;
        bool shiftKey;
        bool altKey;
        bool metaKey;

        uint32_t button;
        uint32_t buttons;

        uint32_t clientX;
        uint32_t clientY;

        uint32_t movementX;
        uint32_t movementY;

        uint32_t offsetX;
        uint32_t offsetY;

        uint32_t pageX;
        uint32_t pageY;

        uint32_t screenX;
        uint32_t screenY;

        uint32_t x;
        uint32_t y;

        // relatedTarget : EventTarget | null;
    };

    enum class KeyCode
    {
        Backspace = 8,
        Tab = 9,
        Enter = 13,
        Shift = 16,
        // ShiftRight = 16,
        Control = 17,
        // ControlRight = 17,
        Alt = 18,
        // AltRight = 18,
        Pause = 19,
        CapsLock = 20,
        Escape = 27,
        Space = 32,
        PageUp = 33,
        PageDown = 34,
        End = 35,
        Home = 36,
        ArrowLeft = 37,
        ArrowUp = 38,
        ArrowRight = 39,
        ArrowDown = 40,
        PrintScreen = 44,
        Insert = 45,
        Delete = 46,
        Digit0 = 48,
        Digit1 = 49,
        Digit2 = 50,
        Digit3 = 51,
        Digit4 = 52,
        Digit5 = 53,
        Digit6 = 54,
        Digit7 = 55,
        Digit8 = 56,
        Digit9 = 57,
        KeyA = 65,
        KeyB = 66,
        KeyC = 67,
        KeyD = 68,
        KeyE = 69,
        KeyF = 70,
        KeyG = 71,
        KeyH = 72,
        KeyI = 73,
        KeyJ = 74,
        KeyK = 75,
        KeyL = 76,
        KeyM = 77,
        KeyN = 78,
        KeyO = 79,
        KeyP = 80,
        KeyQ = 81,
        KeyR = 82,
        KeyS = 83,
        KeyT = 84,
        KeyU = 85,
        KeyV = 86,
        KeyW = 87,
        KeyX = 88,
        KeyY = 89,
        KeyZ = 90,
        MetaLeft = 91,
        MetaRight = 92,
        ContextMenu = 93,
        Numpad0 = 96,
        Numpad1 = 97,
        Numpad2 = 98,
        Numpad3 = 99,
        Numpad4 = 100,
        Numpad5 = 101,
        Numpad6 = 102,
        Numpad7 = 103,
        Numpad8 = 104,
        Numpad9 = 105,
        NumpadMultiply = 106,
        NumpadAdd = 107,
        NumpadSubtract = 109,
        NumpadDecimal = 110,
        NumpadDivide = 111,
        F1 = 112,
        F2 = 113,
        F3 = 114,
        F4 = 115,
        F5 = 116,
        F6 = 117,
        F7 = 118,
        F8 = 119,
        F9 = 120,
        F10 = 121,
        F11 = 122,
        F12 = 123,
        NumLock = 144,
        ScrollLock = 145,
        Semicolon = 186,
        Equal = 187,
        Comma = 188,
        Minus = 189,
        Period = 190,
        Slash = 191,
        Backquote = 192,
        BracketLeft = 219,
        Backslash = 220,
        BracketRight = 221,
        Quote = 222
    };

    /**
     * @brief Keycodes using the "new" format not supported by Ultralight yet (Ultralight does not send event.code"
     * See: https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/code#specifications
     */
    enum class NewKeyEventCode
    {
        Escape = 0x0001,
        Digit1 = 0x0002,
        Digit2 = 0x0003,
        Digit3 = 0x0004,
        Digit4 = 0x0005,
        Digit5 = 0x0006,
        Digit6 = 0x0007,
        Digit7 = 0x0008,
        Digit8 = 0x0009,
        Digit9 = 0x000A,
        Digit0 = 0x000B,
        Minus = 0x000C,
        Equal = 0x000D,
        Backspace = 0x000E,
        Tab = 0x000F,
        KeyQ = 0x0010,
        KeyW = 0x0011,
        KeyE = 0x0012,
        KeyR = 0x0013,
        KeyT = 0x0014,
        KeyY = 0x0015,
        KeyU = 0x0016,
        KeyI = 0x0017,
        KeyO = 0x0018,
        KeyP = 0x0019,
        BracketLeft = 0x001A,
        BracketRight = 0x001B,
        Enter = 0x001C,
        ControlLeft = 0x001D,
        KeyA = 0x001E,
        KeyS = 0x001F,
        KeyD = 0x0020,
        KeyF = 0x0021,
        KeyG = 0x0022,
        KeyH = 0x0023,
        KeyJ = 0x0024,
        KeyK = 0x0025,
        KeyL = 0x0026,
        Semicolon = 0x0027,
        Quote = 0x0028,
        Backquote = 0x0029,
        ShiftLeft = 0x002A,
        Backslash = 0x002B,
        KeyZ = 0x002C,
        KeyX = 0x002D,
        KeyC = 0x002E,
        KeyV = 0x002F,
        KeyB = 0x0030,
        KeyN = 0x0031,
        KeyM = 0x0032,
        Comma = 0x0033,
        Period = 0x0034,
        Slash = 0x0035,
        ShiftRight = 0x0036,
        NumpadMultiply = 0x0037,
        AltLeft = 0x0038,
        Space = 0x0039,
        CapsLock = 0x003A,
        F1 = 0x003B,
        F2 = 0x003C,
        F3 = 0x003D,
        F4 = 0x003E,
        F5 = 0x003F,
        F6 = 0x0040,
        F7 = 0x0041,
        F8 = 0x0042,
        F9 = 0x0043,
        F10 = 0x0044,
        Pause = 0x0045,
        ScrollLock = 0x0046,
        Numpad7 = 0x0047,
        Numpad8 = 0x0048,
        Numpad9 = 0x0049,
        NumpadSubtract = 0x004A,
        Numpad4 = 0x004B,
        Numpad5 = 0x004C,
        Numpad6 = 0x004D,
        NumpadAdd = 0x004E,
        Numpad1 = 0x004F,
        Numpad2 = 0x0050,
        Numpad3 = 0x0051,
        Numpad0 = 0x0052,
        NumpadDecimal = 0x0053,
        IntlBackslash = 0x0056,
        F11 = 0x0057,
        F12 = 0x0058,
        NumpadEqual = 0x0059,
        F13 = 0x0064,
        F14 = 0x0065,
        F15 = 0x0066,
        F16 = 0x0067,
        F17 = 0x0068,
        F18 = 0x0069,
        F19 = 0x006A,
        F20 = 0x006B,
        F21 = 0x006C,
        F22 = 0x006D,
        F23 = 0x006E,
        KanaMode = 0x0070,
        IntlRo = 0x0073,
        F24 = 0x0076,
        Lang4 = 0x0077,
        Lang3 = 0x0078,
        Convert = 0x0079,
        NonConvert = 0x007B,
        IntlYen = 0x007D,
        NumpadComma = 0x007E,
        Undo = 0xE008,
        Paste = 0xE00A,
        MediaTrackPrevious = 0xE010,
        Cut = 0xE017,
        Copy = 0xE018,
        MediaTrackNext = 0xE019,
        NumpadEnter = 0xE01C,
        ControlRight = 0xE01D,
        AudioVolumeMute = 0xE020,
        LaunchApp2 = 0xE021,
        MediaPlayPause = 0xE022,
        MediaStop = 0xE024,
        Eject = 0xE02C,
        AudioVolumeDown = 0xE02E,
        AudioVolumeUp = 0xE030,
        BrowserHome = 0xE032,
        NumpadDivide = 0xE035,
        PrintScreen = 0xE037,
        AltRight = 0xE038,
        Help = 0xE03B,
        NumLock = 0xE045,
        Home = 0xE047,
        ArrowUp = 0xE048,
        PageUp = 0xE049,
        ArrowLeft = 0xE04B,
        ArrowRight = 0xE04D,
        End = 0xE04F,
        ArrowDown = 0xE050,
        PageDown = 0xE051,
        Insert = 0xE052,
        Delete = 0xE053,
        MetaLeft = 0xE05B,
        MetaRight = 0xE05C,
        ContextMenu = 0xE05D,
        Power = 0xE05E,
        Sleep = 0xE05F,
        WakeUp = 0xE063,
        BrowserSearch = 0xE065,
        BrowserFavorites = 0xE066,
        BrowserRefresh = 0xE067,
        BrowserStop = 0xE068,
        BrowserForward = 0xE069,
        BrowserBack = 0xE06A,
        LaunchApp1 = 0xE06B,
        LaunchMail = 0xE06C,
        MediaSelect = 0xE06D,
    };

    inline NewKeyEventCode parseKeyCode(const std::string_view &code)
    {
        switch (hash_djb2a(code))
        {
            case "Escape"_sh:
                return NewKeyEventCode::Escape;
            case "Digit1"_sh:
                return NewKeyEventCode::Digit1;
            case "Digit2"_sh:
                return NewKeyEventCode::Digit2;
            case "Digit3"_sh:
                return NewKeyEventCode::Digit3;
            case "Digit4"_sh:
                return NewKeyEventCode::Digit4;
            case "Digit5"_sh:
                return NewKeyEventCode::Digit5;
            case "Digit6"_sh:
                return NewKeyEventCode::Digit6;
            case "Digit7"_sh:
                return NewKeyEventCode::Digit7;
            case "Digit8"_sh:
                return NewKeyEventCode::Digit8;
            case "Digit9"_sh:
                return NewKeyEventCode::Digit9;
            case "Digit0"_sh:
                return NewKeyEventCode::Digit0;
            case "Minus"_sh:
                return NewKeyEventCode::Minus;
            case "Equal"_sh:
                return NewKeyEventCode::Equal;
            case "Backspace"_sh:
                return NewKeyEventCode::Backspace;
            case "Tab"_sh:
                return NewKeyEventCode::Tab;
            case "KeyQ"_sh:
                return NewKeyEventCode::KeyQ;
            case "KeyW"_sh:
                return NewKeyEventCode::KeyW;
            case "KeyE"_sh:
                return NewKeyEventCode::KeyE;
            case "KeyR"_sh:
                return NewKeyEventCode::KeyR;
            case "KeyT"_sh:
                return NewKeyEventCode::KeyT;
            case "KeyY"_sh:
                return NewKeyEventCode::KeyY;
            case "KeyU"_sh:
                return NewKeyEventCode::KeyU;
            case "KeyI"_sh:
                return NewKeyEventCode::KeyI;
            case "KeyO"_sh:
                return NewKeyEventCode::KeyO;
            case "KeyP"_sh:
                return NewKeyEventCode::KeyP;
            case "BracketLeft"_sh:
                return NewKeyEventCode::BracketLeft;
            case "BracketRight"_sh:
                return NewKeyEventCode::BracketRight;
            case "Enter"_sh:
                return NewKeyEventCode::Enter;
            case "ControlLeft"_sh:
                return NewKeyEventCode::ControlLeft;
            case "KeyA"_sh:
                return NewKeyEventCode::KeyA;
            case "KeyS"_sh:
                return NewKeyEventCode::KeyS;
            case "KeyD"_sh:
                return NewKeyEventCode::KeyD;
            case "KeyF"_sh:
                return NewKeyEventCode::KeyF;
            case "KeyG"_sh:
                return NewKeyEventCode::KeyG;
            case "KeyH"_sh:
                return NewKeyEventCode::KeyH;
            case "KeyJ"_sh:
                return NewKeyEventCode::KeyJ;
            case "KeyK"_sh:
                return NewKeyEventCode::KeyK;
            case "KeyL"_sh:
                return NewKeyEventCode::KeyL;
            case "Semicolon"_sh:
                return NewKeyEventCode::Semicolon;
            case "Quote"_sh:
                return NewKeyEventCode::Quote;
            case "Backquote"_sh:
                return NewKeyEventCode::Backquote;
            case "ShiftLeft"_sh:
                return NewKeyEventCode::ShiftLeft;
            case "Backslash"_sh:
                return NewKeyEventCode::Backslash;
            case "KeyZ"_sh:
                return NewKeyEventCode::KeyZ;
            case "KeyX"_sh:
                return NewKeyEventCode::KeyX;
            case "KeyC"_sh:
                return NewKeyEventCode::KeyC;
            case "KeyV"_sh:
                return NewKeyEventCode::KeyV;
            case "KeyB"_sh:
                return NewKeyEventCode::KeyB;
            case "KeyN"_sh:
                return NewKeyEventCode::KeyN;
            case "KeyM"_sh:
                return NewKeyEventCode::KeyM;
            case "Comma"_sh:
                return NewKeyEventCode::Comma;
            case "Period"_sh:
                return NewKeyEventCode::Period;
            case "Slash"_sh:
                return NewKeyEventCode::Slash;
            case "ShiftRight"_sh:
                return NewKeyEventCode::ShiftRight;
            case "NumpadMultiply"_sh:
                return NewKeyEventCode::NumpadMultiply;
            case "AltLeft"_sh:
                return NewKeyEventCode::AltLeft;
            case "Space"_sh:
                return NewKeyEventCode::Space;
            case "CapsLock"_sh:
                return NewKeyEventCode::CapsLock;
            case "F1"_sh:
                return NewKeyEventCode::F1;
            case "F2"_sh:
                return NewKeyEventCode::F2;
            case "F3"_sh:
                return NewKeyEventCode::F3;
            case "F4"_sh:
                return NewKeyEventCode::F4;
            case "F5"_sh:
                return NewKeyEventCode::F5;
            case "F6"_sh:
                return NewKeyEventCode::F6;
            case "F7"_sh:
                return NewKeyEventCode::F7;
            case "F8"_sh:
                return NewKeyEventCode::F8;
            case "F9"_sh:
                return NewKeyEventCode::F9;
            case "F10"_sh:
                return NewKeyEventCode::F10;
            case "Pause"_sh:
                return NewKeyEventCode::Pause;
            case "ScrollLock"_sh:
                return NewKeyEventCode::ScrollLock;
            case "Numpad7"_sh:
                return NewKeyEventCode::Numpad7;
            case "Numpad8"_sh:
                return NewKeyEventCode::Numpad8;
            case "Numpad9"_sh:
                return NewKeyEventCode::Numpad9;
            case "NumpadSubtract"_sh:
                return NewKeyEventCode::NumpadSubtract;
            case "Numpad4"_sh:
                return NewKeyEventCode::Numpad4;
            case "Numpad5"_sh:
                return NewKeyEventCode::Numpad5;
            case "Numpad6"_sh:
                return NewKeyEventCode::Numpad6;
            case "NumpadAdd"_sh:
                return NewKeyEventCode::NumpadAdd;
            case "Numpad1"_sh:
                return NewKeyEventCode::Numpad1;
            case "Numpad2"_sh:
                return NewKeyEventCode::Numpad2;
            case "Numpad3"_sh:
                return NewKeyEventCode::Numpad3;
            case "Numpad0"_sh:
                return NewKeyEventCode::Numpad0;
            case "NumpadDecimal"_sh:
                return NewKeyEventCode::NumpadDecimal;
            case "IntlBackslash"_sh:
                return NewKeyEventCode::IntlBackslash;
            case "F11"_sh:
                return NewKeyEventCode::F11;
            case "F12"_sh:
                return NewKeyEventCode::F12;
            case "NumpadEqual"_sh:
                return NewKeyEventCode::NumpadEqual;
            case "F13"_sh:
                return NewKeyEventCode::F13;
            case "F14"_sh:
                return NewKeyEventCode::F14;
            case "F15"_sh:
                return NewKeyEventCode::F15;
            case "F16"_sh:
                return NewKeyEventCode::F16;
            case "F17"_sh:
                return NewKeyEventCode::F17;
            case "F18"_sh:
                return NewKeyEventCode::F18;
            case "F19"_sh:
                return NewKeyEventCode::F19;
            case "F20"_sh:
                return NewKeyEventCode::F20;
            case "F21"_sh:
                return NewKeyEventCode::F21;
            case "F22"_sh:
                return NewKeyEventCode::F22;
            case "F23"_sh:
                return NewKeyEventCode::F23;
            case "KanaMode"_sh:
                return NewKeyEventCode::KanaMode;
            case "IntlRo"_sh:
                return NewKeyEventCode::IntlRo;
            case "F24"_sh:
                return NewKeyEventCode::F24;
            case "Lang4"_sh:
                return NewKeyEventCode::Lang4;
            case "Lang3"_sh:
                return NewKeyEventCode::Lang3;
            case "Convert"_sh:
                return NewKeyEventCode::Convert;
            case "NonConvert"_sh:
                return NewKeyEventCode::NonConvert;
            case "IntlYen"_sh:
                return NewKeyEventCode::IntlYen;
            case "NumpadComma"_sh:
                return NewKeyEventCode::NumpadComma;
            case "Undo"_sh:
                return NewKeyEventCode::Undo;
            case "Paste"_sh:
                return NewKeyEventCode::Paste;
            case "MediaTrackPrevious"_sh:
                return NewKeyEventCode::MediaTrackPrevious;
            case "Cut"_sh:
                return NewKeyEventCode::Cut;
            case "Copy"_sh:
                return NewKeyEventCode::Copy;
            case "MediaTrackNext"_sh:
                return NewKeyEventCode::MediaTrackNext;
            case "NumpadEnter"_sh:
                return NewKeyEventCode::NumpadEnter;
            case "ControlRight"_sh:
                return NewKeyEventCode::ControlRight;
            case "AudioVolumeMute"_sh:
                return NewKeyEventCode::AudioVolumeMute;
            case "LaunchApp2"_sh:
                return NewKeyEventCode::LaunchApp2;
            case "MediaPlayPause"_sh:
                return NewKeyEventCode::MediaPlayPause;
            case "MediaStop"_sh:
                return NewKeyEventCode::MediaStop;
            case "Eject"_sh:
                return NewKeyEventCode::Eject;
            case "AudioVolumeDown"_sh:
                return NewKeyEventCode::AudioVolumeDown;
            case "AudioVolumeUp"_sh:
                return NewKeyEventCode::AudioVolumeUp;
            case "BrowserHome"_sh:
                return NewKeyEventCode::BrowserHome;
            case "NumpadDivide"_sh:
                return NewKeyEventCode::NumpadDivide;
            case "PrintScreen"_sh:
                return NewKeyEventCode::PrintScreen;
            case "AltRight"_sh:
                return NewKeyEventCode::AltRight;
            case "Help"_sh:
                return NewKeyEventCode::Help;
            case "NumLock"_sh:
                return NewKeyEventCode::NumLock;
            case "Home"_sh:
                return NewKeyEventCode::Home;
            case "ArrowUp"_sh:
                return NewKeyEventCode::ArrowUp;
            case "PageUp"_sh:
                return NewKeyEventCode::PageUp;
            case "ArrowLeft"_sh:
                return NewKeyEventCode::ArrowLeft;
            case "ArrowRight"_sh:
                return NewKeyEventCode::ArrowRight;
            case "End"_sh:
                return NewKeyEventCode::End;
            case "ArrowDown"_sh:
                return NewKeyEventCode::ArrowDown;
            case "PageDown"_sh:
                return NewKeyEventCode::PageDown;
            case "Insert"_sh:
                return NewKeyEventCode::Insert;
            case "Delete"_sh:
                return NewKeyEventCode::Delete;
            case "MetaLeft"_sh:
                return NewKeyEventCode::MetaLeft;
            case "MetaRight"_sh:
                return NewKeyEventCode::MetaRight;
            case "ContextMenu"_sh:
                return NewKeyEventCode::ContextMenu;
            case "Power"_sh:
                return NewKeyEventCode::Power;
            case "Sleep"_sh:
                return NewKeyEventCode::Sleep;
            case "WakeUp"_sh:
                return NewKeyEventCode::WakeUp;
            case "BrowserSearch"_sh:
                return NewKeyEventCode::BrowserSearch;
            case "BrowserFavorites"_sh:
                return NewKeyEventCode::BrowserFavorites;
            case "BrowserRefresh"_sh:
                return NewKeyEventCode::BrowserRefresh;
            case "BrowserStop"_sh:
                return NewKeyEventCode::BrowserStop;
            case "BrowserForward"_sh:
                return NewKeyEventCode::BrowserForward;
            case "BrowserBack"_sh:
                return NewKeyEventCode::BrowserBack;
            case "LaunchApp1"_sh:
                return NewKeyEventCode::LaunchApp1;
            case "LaunchMail"_sh:
                return NewKeyEventCode::LaunchMail;
            case "MediaSelect"_sh:
                return NewKeyEventCode::MediaSelect;
        }
    }

    // https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/location
    enum class KeyboardEventLocation
    {
        DOM_KEY_LOCATION_STANDARD = 0,
        DOM_KEY_LOCATION_LEFT = 1,
        DOM_KEY_LOCATION_RIGHT = 2,
        DOM_KEY_LOCATION_NUMPAD = 3,
        DOM_KEY_LOCATION_MOBILE = 4,
        DOM_KEY_LOCATION_JOYSTICK = 5
    };

    struct KeyboardEvent
    {
        // Currently not sent by Ultralight
        // std::string code;

        // Currently not sent by Ultralight
        // KeyboardEventLocation location;
        KeyCode keycode;
        bool ctrlKey;
        bool shiftKey;
        bool altKey;
        // Unused
        // bool isComposing;
        // std::string key;

        bool repeat;
        bool metaKey;
    };

    inline std::ostream &operator<<(std::ostream &os, const MouseEventType &type)
    {
        switch (type)
        {
            case MouseEventType::DoubleClick:
                return os << "dblclick";
            case MouseEventType::MouseDown:
                return os << "mousedown";
            case MouseEventType::MouseEnter:
                return os << "mouseenter";
            case MouseEventType::MouseLeave:
                return os << "mouseleave";
            case MouseEventType::MouseMove:
                return os << "mousemove";
            case MouseEventType::MouseOut:
                return os << "mouseout";
            case MouseEventType::MouseOver:
                return os << "mouseover";
            case MouseEventType::MouseUp:
                return os << "mouseup";
            default:
                return os << "[Unknown MouseEventType]";
        }
    }

    inline std::ostream &operator<<(std::ostream &os, const KeyCode &keyCode)
    {
        switch (keyCode)
        {
            case KeyCode::Backspace:
                return os << "Backspace";
            case KeyCode::Tab:
                return os << "Tab";
            case KeyCode::Enter:
                return os << "Enter";
            case KeyCode::Shift:
                return os << "Shift";
            // case KeyCode::ShiftRight:
            //     return os << "ShiftRight";
            case KeyCode::Control:
                return os << "Control";
            // case KeyCode::ControlRight:
            //     return os << "ControlRight";
            case KeyCode::Alt:
                return os << "Alt";
            // case KeyCode::AltRight:
            //     return os << "AltRight";
            case KeyCode::Pause:
                return os << "Pause";
            case KeyCode::CapsLock:
                return os << "CapsLock";
            case KeyCode::Escape:
                return os << "Escape";
            case KeyCode::Space:
                return os << "Space";
            case KeyCode::PageUp:
                return os << "PageUp";
            case KeyCode::PageDown:
                return os << "PageDown";
            case KeyCode::End:
                return os << "End";
            case KeyCode::Home:
                return os << "Home";
            case KeyCode::ArrowLeft:
                return os << "ArrowLeft";
            case KeyCode::ArrowUp:
                return os << "ArrowUp";
            case KeyCode::ArrowRight:
                return os << "ArrowRight";
            case KeyCode::ArrowDown:
                return os << "ArrowDown";
            case KeyCode::PrintScreen:
                return os << "PrintScreen";
            case KeyCode::Insert:
                return os << "Insert";
            case KeyCode::Delete:
                return os << "Delete";
            case KeyCode::Digit0:
                return os << "Digit0";
            case KeyCode::Digit1:
                return os << "Digit1";
            case KeyCode::Digit2:
                return os << "Digit2";
            case KeyCode::Digit3:
                return os << "Digit3";
            case KeyCode::Digit4:
                return os << "Digit4";
            case KeyCode::Digit5:
                return os << "Digit5";
            case KeyCode::Digit6:
                return os << "Digit6";
            case KeyCode::Digit7:
                return os << "Digit7";
            case KeyCode::Digit8:
                return os << "Digit8";
            case KeyCode::Digit9:
                return os << "Digit9";
            case KeyCode::KeyA:
                return os << "KeyA";
            case KeyCode::KeyB:
                return os << "KeyB";
            case KeyCode::KeyC:
                return os << "KeyC";
            case KeyCode::KeyD:
                return os << "KeyD";
            case KeyCode::KeyE:
                return os << "KeyE";
            case KeyCode::KeyF:
                return os << "KeyF";
            case KeyCode::KeyG:
                return os << "KeyG";
            case KeyCode::KeyH:
                return os << "KeyH";
            case KeyCode::KeyI:
                return os << "KeyI";
            case KeyCode::KeyJ:
                return os << "KeyJ";
            case KeyCode::KeyK:
                return os << "KeyK";
            case KeyCode::KeyL:
                return os << "KeyL";
            case KeyCode::KeyM:
                return os << "KeyM";
            case KeyCode::KeyN:
                return os << "KeyN";
            case KeyCode::KeyO:
                return os << "KeyO";
            case KeyCode::KeyP:
                return os << "KeyP";
            case KeyCode::KeyQ:
                return os << "KeyQ";
            case KeyCode::KeyR:
                return os << "KeyR";
            case KeyCode::KeyS:
                return os << "KeyS";
            case KeyCode::KeyT:
                return os << "KeyT";
            case KeyCode::KeyU:
                return os << "KeyU";
            case KeyCode::KeyV:
                return os << "KeyV";
            case KeyCode::KeyW:
                return os << "KeyW";
            case KeyCode::KeyX:
                return os << "KeyX";
            case KeyCode::KeyY:
                return os << "KeyY";
            case KeyCode::KeyZ:
                return os << "KeyZ";
            case KeyCode::MetaLeft:
                return os << "MetaLeft";
            case KeyCode::MetaRight:
                return os << "MetaRight";
            case KeyCode::ContextMenu:
                return os << "ContextMenu";
            case KeyCode::Numpad0:
                return os << "Numpad0";
            case KeyCode::Numpad1:
                return os << "Numpad1";
            case KeyCode::Numpad2:
                return os << "Numpad2";
            case KeyCode::Numpad3:
                return os << "Numpad3";
            case KeyCode::Numpad4:
                return os << "Numpad4";
            case KeyCode::Numpad5:
                return os << "Numpad5";
            case KeyCode::Numpad6:
                return os << "Numpad6";
            case KeyCode::Numpad7:
                return os << "Numpad7";
            case KeyCode::Numpad8:
                return os << "Numpad8";
            case KeyCode::Numpad9:
                return os << "Numpad9";
            case KeyCode::NumpadMultiply:
                return os << "NumpadMultiply";
            case KeyCode::NumpadAdd:
                return os << "NumpadAdd";
            case KeyCode::NumpadSubtract:
                return os << "NumpadSubtract";
            case KeyCode::NumpadDecimal:
                return os << "NumpadDecimal";
            case KeyCode::NumpadDivide:
                return os << "NumpadDivide";
            case KeyCode::F1:
                return os << "F1";
            case KeyCode::F2:
                return os << "F2";
            case KeyCode::F3:
                return os << "F3";
            case KeyCode::F4:
                return os << "F4";
            case KeyCode::F5:
                return os << "F5";
            case KeyCode::F6:
                return os << "F6";
            case KeyCode::F7:
                return os << "F7";
            case KeyCode::F8:
                return os << "F8";
            case KeyCode::F9:
                return os << "F9";
            case KeyCode::F10:
                return os << "F10";
            case KeyCode::F11:
                return os << "F11";
            case KeyCode::F12:
                return os << "F12";
            case KeyCode::NumLock:
                return os << "NumLock";
            case KeyCode::ScrollLock:
                return os << "ScrollLock";
            case KeyCode::Semicolon:
                return os << "Semicolon";
            case KeyCode::Equal:
                return os << "Equal";
            case KeyCode::Comma:
                return os << "Comma";
            case KeyCode::Minus:
                return os << "Minus";
            case KeyCode::Period:
                return os << "Period";
            case KeyCode::Slash:
                return os << "Slash";
            case KeyCode::Backquote:
                return os << "Backquote";
            case KeyCode::BracketLeft:
                return os << "BracketLeft";
            case KeyCode::Backslash:
                return os << "Backslash";
            case KeyCode::BracketRight:
                return os << "BracketRight";
            case KeyCode::Quote:
                return os << "Quote";
            default:
                return os << "Unidentified";
        }
    }

    inline std::ostream &operator<<(std::ostream &os, const MouseEvent &e)
    {
        return os << fmt::format("{{ type: {}, offsetX: {}, offsetY: {}, clientX: {}, clientY: {} }}", e.type, e.offsetX, e.offsetY, e.clientX, e.clientY);
    }

    inline std::ostream &operator<<(std::ostream &os, const KeyboardEvent &e)
    {
        os << "{ name=" << e.keycode << ", keyCode=" << static_cast<int>(e.keycode);
        if (e.ctrlKey)
        {
            os << " | "
               << "CTRL";
        }
        if (e.shiftKey)
        {
            os << " | "
               << "SHIFT";
        }
        if (e.altKey)
        {
            os << " | "
               << "ALT";
        }
        if (e.repeat)
        {
            os << " | "
               << "REPEAT";
        }
        if (e.metaKey)
        {
            os << " | "
               << "META";
        }

        //         keycode
        // ctrlKey
        // shiftKey
        // altKey
        // metaKey
        // repeat
        return os << " }";
    }

} // namespace JSEvent