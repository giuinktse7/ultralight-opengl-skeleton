#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Keycodes
{
    // GK_BACK (08) BACKSPACE key
    constexpr int C_GK_BACK = 0x08;

    // GK_TAB (09) TAB key
    constexpr int C_GK_TAB = 0x09;

    // GK_CLEAR (0C) CLEAR key
    constexpr int C_GK_CLEAR = 0x0C;

    // GK_RETURN (0D)
    constexpr int C_GK_RETURN = 0x0D;

    // GK_SHIFT (10) SHIFT key
    constexpr int C_GK_SHIFT = 0x10;

    // GK_CONTROL (11) CTRL key
    constexpr int C_GK_CONTROL = 0x11;

    // GK_MENU (12) ALT key
    constexpr int C_GK_MENU = 0x12;

    // GK_PAUSE (13) PAUSE key
    constexpr int C_GK_PAUSE = 0x13;

    // GK_CAPITAL (14) CAPS LOCK key
    constexpr int C_GK_CAPITAL = 0x14;

    // GK_KANA (15) Input Method Editor (IME) Kana mode
    constexpr int C_GK_KANA = 0x15;

    // GK_HANGUEL (15) IME Hanguel mode (maintained for compatibility; use GK_HANGUL)
    // GK_HANGUL (15) IME Hangul mode
    constexpr int C_GK_HANGUL = 0x15;

    // GK_IME_ON (16) IME On
    constexpr int C_GK_IME_ON = 0x16;

    // GK_JUNJA (17) IME Junja mode
    constexpr int C_GK_JUNJA = 0x17;

    // GK_FINAL (18) IME final mode
    constexpr int C_GK_FINAL = 0x18;

    // GK_HANJA (19) IME Hanja mode
    constexpr int C_GK_HANJA = 0x19;

    // GK_KANJI (19) IME Kanji mode
    constexpr int C_GK_KANJI = 0x19;

    // GK_IME_OFF (1A) IME Off
    constexpr int C_GK_IME_OFF = 0x1A;

    // GK_ESCAPE (1B) ESC key
    constexpr int C_GK_ESCAPE = 0x1B;

    // GK_CONVERT (1C) IME convert
    constexpr int C_GK_CONVERT = 0x1C;

    // GK_NONCONVERT (1D) IME nonconvert
    constexpr int C_GK_NONCONVERT = 0x1D;

    // GK_ACCEPT (1E) IME accept
    constexpr int C_GK_ACCEPT = 0x1E;

    // GK_MODECHANGE (1F) IME mode change request
    constexpr int C_GK_MODECHANGE = 0x1F;

    // GK_SPACE (20) SPACEBAR
    constexpr int C_GK_SPACE = 0x20;

    // GK_PRIOR (21) PAGE UP key
    constexpr int C_GK_PRIOR = 0x21;

    // GK_NEXT (22) PAGE DOWN key
    constexpr int C_GK_NEXT = 0x22;

    // GK_END (23) END key
    constexpr int C_GK_END = 0x23;

    // GK_HOME (24) HOME key
    constexpr int C_GK_HOME = 0x24;

    // GK_LEFT (25) LEFT ARROW key
    constexpr int C_GK_LEFT = 0x25;

    // GK_UP (26) UP ARROW key
    constexpr int C_GK_UP = 0x26;

    // GK_RIGHT (27) RIGHT ARROW key
    constexpr int C_GK_RIGHT = 0x27;

    // GK_DOWN (28) DOWN ARROW key
    constexpr int C_GK_DOWN = 0x28;

    // GK_SELECT (29) SELECT key
    constexpr int C_GK_SELECT = 0x29;

    // GK_PRINT (2A) PRINT key
    constexpr int C_GK_PRINT = 0x2A;

    // GK_EXECUTE (2B) EXECUTE key
    constexpr int C_GK_EXECUTE = 0x2B;

    // GK_SNAPSHOT (2C) PRINT SCREEN key
    constexpr int C_GK_SNAPSHOT = 0x2C;

    // GK_INSERT (2D) INS key
    constexpr int C_GK_INSERT = 0x2D;

    // GK_DELETE (2E) DEL key
    constexpr int C_GK_DELETE = 0x2E;

    // GK_HELP (2F) HELP key
    constexpr int C_GK_HELP = 0x2F;

    // (30) 0 key
    constexpr int C_GK_0 = 0x30;

    // (31) 1 key
    constexpr int C_GK_1 = 0x31;

    // (32) 2 key
    constexpr int C_GK_2 = 0x32;

    // (33) 3 key
    constexpr int C_GK_3 = 0x33;

    // (34) 4 key
    constexpr int C_GK_4 = 0x34;

    // (35) 5 key;
    constexpr int C_GK_5 = 0x35;

    // (36) 6 key
    constexpr int C_GK_6 = 0x36;

    // (37) 7 key
    constexpr int C_GK_7 = 0x37;

    // (38) 8 key
    constexpr int C_GK_8 = 0x38;

    // (39) 9 key
    constexpr int C_GK_9 = 0x39;

    // (41) A key
    constexpr int C_GK_A = 0x41;

    // (42) B key
    constexpr int C_GK_B = 0x42;

    // (43) C key
    constexpr int C_GK_C = 0x43;

    // (44) D key
    constexpr int C_GK_D = 0x44;

    // (45) E key
    constexpr int C_GK_E = 0x45;

    // (46) F key
    constexpr int C_GK_F = 0x46;

    // (47) G key
    constexpr int C_GK_G = 0x47;

    // (48) H key
    constexpr int C_GK_H = 0x48;

    // (49) I key
    constexpr int C_GK_I = 0x49;

    // (4A) J key
    constexpr int C_GK_J = 0x4A;

    // (4B) K key
    constexpr int C_GK_K = 0x4B;

    // (4C) L key
    constexpr int C_GK_L = 0x4C;

    // (4D) M key
    constexpr int C_GK_M = 0x4D;

    // (4E) N key
    constexpr int C_GK_N = 0x4E;

    // (4F) O key
    constexpr int C_GK_O = 0x4F;

    // (50) P key
    constexpr int C_GK_P = 0x50;

    // (51) Q key
    constexpr int C_GK_Q = 0x51;

    // (52) R key
    constexpr int C_GK_R = 0x52;

    // (53) S key
    constexpr int C_GK_S = 0x53;

    // (54) T key
    constexpr int C_GK_T = 0x54;

    // (55) U key
    constexpr int C_GK_U = 0x55;

    // (56) V key
    constexpr int C_GK_V = 0x56;

    // (57) W key
    constexpr int C_GK_W = 0x57;

    // (58) X key
    constexpr int C_GK_X = 0x58;

    // (59) Y key
    constexpr int C_GK_Y = 0x59;

    // (5A) Z key
    constexpr int C_GK_Z = 0x5A;

    // GK_LWIN (5B) Left Windows key (Microsoft Natural keyboard)
    constexpr int C_GK_LWIN = 0x5B;

    // GK_RWIN (5C) Right Windows key (Natural keyboard)
    constexpr int C_GK_RWIN = 0x5C;

    // GK_APPS (5D) Applications key (Natural keyboard)
    constexpr int C_GK_APPS = 0x5D;

    // GK_SLEEP (5F) Computer Sleep key
    constexpr int C_GK_SLEEP = 0x5F;

    // GK_NUMPAD0 (60) Numeric keypad 0 key
    constexpr int C_GK_NUMPAD0 = 0x60;

    // GK_NUMPAD1 (61) Numeric keypad 1 key
    constexpr int C_GK_NUMPAD1 = 0x61;

    // GK_NUMPAD2 (62) Numeric keypad 2 key
    constexpr int C_GK_NUMPAD2 = 0x62;

    // GK_NUMPAD3 (63) Numeric keypad 3 key
    constexpr int C_GK_NUMPAD3 = 0x63;

    // GK_NUMPAD4 (64) Numeric keypad 4 key
    constexpr int C_GK_NUMPAD4 = 0x64;

    // GK_NUMPAD5 (65) Numeric keypad 5 key
    constexpr int C_GK_NUMPAD5 = 0x65;

    // GK_NUMPAD6 (66) Numeric keypad 6 key
    constexpr int C_GK_NUMPAD6 = 0x66;

    // GK_NUMPAD7 (67) Numeric keypad 7 key
    constexpr int C_GK_NUMPAD7 = 0x67;

    // GK_NUMPAD8 (68) Numeric keypad 8 key
    constexpr int C_GK_NUMPAD8 = 0x68;

    // GK_NUMPAD9 (69) Numeric keypad 9 key
    constexpr int C_GK_NUMPAD9 = 0x69;

    // GK_MULTIPLY (6A) Multiply key
    constexpr int C_GK_MULTIPLY = 0x6A;

    // GK_ADD (6B) Add key
    constexpr int C_GK_ADD = 0x6B;

    // GK_SEPARATOR (6C) Separator key
    constexpr int C_GK_SEPARATOR = 0x6C;

    // GK_SUBTRACT (6D) Subtract key
    constexpr int C_GK_SUBTRACT = 0x6D;

    // GK_DECIMAL (6E) Decimal key
    constexpr int C_GK_DECIMAL = 0x6E;

    // GK_DIVIDE (6F) Divide key
    constexpr int C_GK_DIVIDE = 0x6F;

    // GK_F1 (70) F1 key
    constexpr int C_GK_F1 = 0x70;

    // GK_F2 (71) F2 key
    constexpr int C_GK_F2 = 0x71;

    // GK_F3 (72) F3 key
    constexpr int C_GK_F3 = 0x72;

    // GK_F4 (73) F4 key
    constexpr int C_GK_F4 = 0x73;

    // GK_F5 (74) F5 key
    constexpr int C_GK_F5 = 0x74;

    // GK_F6 (75) F6 key
    constexpr int C_GK_F6 = 0x75;

    // GK_F7 (76) F7 key
    constexpr int C_GK_F7 = 0x76;

    // GK_F8 (77) F8 key
    constexpr int C_GK_F8 = 0x77;

    // GK_F9 (78) F9 key
    constexpr int C_GK_F9 = 0x78;

    // GK_F10 (79) F10 key
    constexpr int C_GK_F10 = 0x79;

    // GK_F11 (7A) F11 key
    constexpr int C_GK_F11 = 0x7A;

    // GK_F12 (7B) F12 key
    constexpr int C_GK_F12 = 0x7B;

    // GK_F13 (7C) F13 key
    constexpr int C_GK_F13 = 0x7C;

    // GK_F14 (7D) F14 key
    constexpr int C_GK_F14 = 0x7D;

    // GK_F15 (7E) F15 key
    constexpr int C_GK_F15 = 0x7E;

    // GK_F16 (7F) F16 key
    constexpr int C_GK_F16 = 0x7F;

    // GK_F17 (80H) F17 key
    constexpr int C_GK_F17 = 0x80;

    // GK_F18 (81H) F18 key
    constexpr int C_GK_F18 = 0x81;

    // GK_F19 (82H) F19 key
    constexpr int C_GK_F19 = 0x82;

    // GK_F20 (83H) F20 key
    constexpr int C_GK_F20 = 0x83;

    // GK_F21 (84H) F21 key
    constexpr int C_GK_F21 = 0x84;

    // GK_F22 (85H) F22 key
    constexpr int C_GK_F22 = 0x85;

    // GK_F23 (86H) F23 key
    constexpr int C_GK_F23 = 0x86;

    // GK_F24 (87H) F24 key
    constexpr int C_GK_F24 = 0x87;

    // GK_NUMLOCK (90) NUM LOCK key
    constexpr int C_GK_NUMLOCK = 0x90;

    // GK_SCROLL (91) SCROLL LOCK key
    constexpr int C_GK_SCROLL = 0x91;

    // GK_LSHIFT (A0) Left SHIFT key
    constexpr int C_GK_LSHIFT = 0xA0;

    // GK_RSHIFT (A1) Right SHIFT key
    constexpr int C_GK_RSHIFT = 0xA1;

    // GK_LCONTROL (A2) Left CONTROL key
    constexpr int C_GK_LCONTROL = 0xA2;

    // GK_RCONTROL (A3) Right CONTROL key
    constexpr int C_GK_RCONTROL = 0xA3;

    // GK_LMENU (A4) Left MENU key
    constexpr int C_GK_LMENU = 0xA4;

    // GK_RMENU (A5) Right MENU key
    constexpr int C_GK_RMENU = 0xA5;

    // GK_BROWSER_BACK (A6) Windows 2000/XP: Browser Back key
    constexpr int C_GK_BROWSER_BACK = 0xA6;

    // GK_BROWSER_FORWARD (A7) Windows 2000/XP: Browser Forward key
    constexpr int C_GK_BROWSER_FORWARD = 0xA7;

    // GK_BROWSER_REFRESH (A8) Windows 2000/XP: Browser Refresh key
    constexpr int C_GK_BROWSER_REFRESH = 0xA8;

    // GK_BROWSER_STOP (A9) Windows 2000/XP: Browser Stop key
    constexpr int C_GK_BROWSER_STOP = 0xA9;

    // GK_BROWSER_SEARCH (AA) Windows 2000/XP: Browser Search key
    constexpr int C_GK_BROWSER_SEARCH = 0xAA;

    // GK_BROWSER_FAVORITES (AB) Windows 2000/XP: Browser Favorites key
    constexpr int C_GK_BROWSER_FAVORITES = 0xAB;

    // GK_BROWSER_HOME (AC) Windows 2000/XP: Browser Start and Home key
    constexpr int C_GK_BROWSER_HOME = 0xAC;

    // GK_VOLUME_MUTE (AD) Windows 2000/XP: Volume Mute key
    constexpr int C_GK_VOLUME_MUTE = 0xAD;

    // GK_VOLUME_DOWN (AE) Windows 2000/XP: Volume Down key
    constexpr int C_GK_VOLUME_DOWN = 0xAE;

    // GK_VOLUME_UP (AF) Windows 2000/XP: Volume Up key
    constexpr int C_GK_VOLUME_UP = 0xAF;

    // GK_MEDIA_NEXT_TRACK (B0) Windows 2000/XP: Next Track key
    constexpr int C_GK_MEDIA_NEXT_TRACK = 0xB0;

    // GK_MEDIA_PREV_TRACK (B1) Windows 2000/XP: Previous Track key
    constexpr int C_GK_MEDIA_PREV_TRACK = 0xB1;

    // GK_MEDIA_STOP (B2) Windows 2000/XP: Stop Media key
    constexpr int C_GK_MEDIA_STOP = 0xB2;

    // GK_MEDIA_PLAY_PAUSE (B3) Windows 2000/XP: Play/Pause Media key
    constexpr int C_GK_MEDIA_PLAY_PAUSE = 0xB3;

    // GK_LAUNCH_MAIL (B4) Windows 2000/XP: Start Mail key
    constexpr int C_GK_MEDIA_LAUNCH_MAIL = 0xB4;

    // GK_LAUNCH_MEDIA_SELECT (B5) Windows 2000/XP: Select Media key
    constexpr int C_GK_MEDIA_LAUNCH_MEDIA_SELECT = 0xB5;

    // GK_LAUNCH_APP1 (B6) Windows 2000/XP: Start Application 1 key
    constexpr int C_GK_MEDIA_LAUNCH_APP1 = 0xB6;

    // GK_LAUNCH_APP2 (B7) Windows 2000/XP: Start Application 2 key
    constexpr int C_GK_MEDIA_LAUNCH_APP2 = 0xB7;

    // GK_OEM_1 (BA) ';:' for US
    constexpr int C_GK_OEM_1 = 0xBA;

    // GK_OEM_PLUS (BB) '=+' any country
    constexpr int C_GK_OEM_PLUS = 0xBB;

    // GK_OEM_COMMA (BC) ',<' any country
    constexpr int C_GK_OEM_COMMA = 0xBC;

    // GK_OEM_MINUS (BD) '-_' any country
    constexpr int C_GK_OEM_MINUS = 0xBD;

    // GK_OEM_PERIOD (BE) '.>' any country
    constexpr int C_GK_OEM_PERIOD = 0xBE;

    // GK_OEM_2 (BF) '/?' for US
    constexpr int C_GK_OEM_2 = 0xBF;

    // GK_OEM_3 (C0) '`~' for US
    constexpr int C_GK_OEM_3 = 0xC0;

    // GK_OEM_4 (DB) '[{' for US
    constexpr int C_GK_OEM_4 = 0xDB;

    // GK_OEM_5 (DC) '\|' for US
    constexpr int C_GK_OEM_5 = 0xDC;

    // GK_OEM_6 (DD) ']}' for US
    constexpr int C_GK_OEM_6 = 0xDD;

    // GK_OEM_7 (DE) ''"' for US
    constexpr int C_GK_OEM_7 = 0xDE;

    // GK_OEM_8 (DF) Used for miscellaneous characters; it can vary by keyboard.
    constexpr int C_GK_OEM_8 = 0xDF;

    // GK_OEM_102 (E2) Windows 2000/XP: Either the angle bracket key or the backslash key on the RT
    // 102-key keyboard
    constexpr int C_GK_OEM_102 = 0xE2;

    // GK_PROCESSKEY (E5) Windows 95/98/Me, Windows NT 4.0, Windows 2000/XP: IME PROCESS key
    constexpr int C_GK_PROCESSKEY = 0xE5;

    // GK_PACKET (E7) Windows 2000/XP: Used to pass Unicode characters as if they were keystrokes. The
    // GK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods.
    // For more information, see Remark in KEYBDINPUT,SendInput, WM_KEYDOWN, and WM_KEYUP
    constexpr int C_GK_PACKET = 0xE7;

    constexpr int C_GK_OEM_ATTN = 0xF0;

    // GK_ATTN (F6) Attn key
    constexpr int C_GK_ATTN = 0xF6;

    // GK_CRSEL (F7) CrSel key
    constexpr int C_GK_CRSEL = 0xF7;

    // GK_EXSEL (F8) ExSel key
    constexpr int C_GK_EXSEL = 0xF8;

    // GK_EREOF (F9) Erase EOF key
    constexpr int C_GK_EREOF = 0xF9;

    // GK_PLAY (FA) Play key
    constexpr int C_GK_PLAY = 0xFA;

    // GK_ZOOM (FB) Zoom key
    constexpr int C_GK_ZOOM = 0xFB;

    // GK_NONAME (FC) Reserved for future use
    constexpr int C_GK_NONAME = 0xFC;

    // GK_PA1 (FD) PA1 key
    constexpr int C_GK_PA1 = 0xFD;

    // GK_OEM_CLEAR (FE) Clear key
    constexpr int C_GK_OEM_CLEAR = 0xFE;

    constexpr int C_GK_UNKNOWN = 0;

    struct JSKeyMap
    {
        static constexpr int Size = 512;
        constexpr JSKeyMap()
            : arr()
        {
            arr[32] = C_GK_SPACE;
            arr[222] = C_GK_OEM_7;
            arr[188] = C_GK_OEM_COMMA;
            arr[45] = C_GK_OEM_MINUS;
            arr[190] = C_GK_OEM_PERIOD;
            arr[191] = C_GK_OEM_2;
            arr[48] = C_GK_0;
            arr[49] = C_GK_1;
            arr[50] = C_GK_2;
            arr[51] = C_GK_3;
            arr[52] = C_GK_4;
            arr[53] = C_GK_5;
            arr[54] = C_GK_6;
            arr[55] = C_GK_7;
            arr[56] = C_GK_8;
            arr[57] = C_GK_9;
            arr[186] = C_GK_OEM_1;
            arr[187] = C_GK_OEM_PLUS;
            arr[GLFW_KEY_A] = C_GK_A;
            arr[GLFW_KEY_B] = C_GK_B;
            arr[GLFW_KEY_C] = C_GK_C;
            arr[GLFW_KEY_D] = C_GK_D;
            arr[GLFW_KEY_E] = C_GK_E;
            arr[GLFW_KEY_F] = C_GK_F;
            arr[GLFW_KEY_G] = C_GK_G;
            arr[GLFW_KEY_H] = C_GK_H;
            arr[GLFW_KEY_I] = C_GK_I;
            arr[GLFW_KEY_J] = C_GK_J;
            arr[GLFW_KEY_K] = C_GK_K;
            arr[GLFW_KEY_L] = C_GK_L;
            arr[GLFW_KEY_M] = C_GK_M;
            arr[GLFW_KEY_N] = C_GK_N;
            arr[GLFW_KEY_O] = C_GK_O;
            arr[GLFW_KEY_P] = C_GK_P;
            arr[GLFW_KEY_Q] = C_GK_Q;
            arr[GLFW_KEY_R] = C_GK_R;
            arr[GLFW_KEY_S] = C_GK_S;
            arr[GLFW_KEY_T] = C_GK_T;
            arr[GLFW_KEY_U] = C_GK_U;
            arr[GLFW_KEY_V] = C_GK_V;
            arr[GLFW_KEY_W] = C_GK_W;
            arr[GLFW_KEY_X] = C_GK_X;
            arr[GLFW_KEY_Y] = C_GK_Y;
            arr[GLFW_KEY_Z] = C_GK_Z;
            arr[219] = C_GK_OEM_4;
            arr[220] = C_GK_OEM_5;
            arr[221] = C_GK_OEM_6;
            arr[192] = C_GK_OEM_3;
            arr[GLFW_KEY_WORLD_1] = C_GK_UNKNOWN;
            arr[GLFW_KEY_WORLD_2] = C_GK_UNKNOWN;
            arr[27] = C_GK_ESCAPE;
            arr[13] = C_GK_RETURN;
            arr[9] = C_GK_TAB;
            arr[8] = C_GK_BACK;
            arr[45] = C_GK_INSERT;
            arr[46] = C_GK_DELETE;
            arr[39] = C_GK_RIGHT;
            arr[37] = C_GK_LEFT;
            arr[40] = C_GK_DOWN;
            arr[38] = C_GK_UP;
            arr[33] = C_GK_PRIOR;
            arr[34] = C_GK_NEXT;
            arr[36] = C_GK_HOME;
            arr[35] = C_GK_END;
            arr[20] = C_GK_CAPITAL;
            arr[145] = C_GK_SCROLL;
            arr[144] = C_GK_NUMLOCK;
            arr[GLFW_KEY_PRINT_SCREEN] = C_GK_SNAPSHOT;
            arr[19] = C_GK_PAUSE;
            arr[112] = C_GK_F1;
            arr[113] = C_GK_F2;
            arr[114] = C_GK_F3;
            arr[115] = C_GK_F4;
            arr[116] = C_GK_F5;
            arr[117] = C_GK_F6;
            arr[118] = C_GK_F7;
            arr[119] = C_GK_F8;
            arr[120] = C_GK_F9;
            arr[121] = C_GK_F10;
            arr[122] = C_GK_F11;
            arr[123] = C_GK_F12;
            arr[GLFW_KEY_F13] = C_GK_F13;
            arr[GLFW_KEY_F14] = C_GK_F14;
            arr[GLFW_KEY_F15] = C_GK_F15;
            arr[GLFW_KEY_F16] = C_GK_F16;
            arr[GLFW_KEY_F17] = C_GK_F17;
            arr[GLFW_KEY_F18] = C_GK_F18;
            arr[GLFW_KEY_F19] = C_GK_F19;
            arr[GLFW_KEY_F20] = C_GK_F20;
            arr[GLFW_KEY_F21] = C_GK_F21;
            arr[GLFW_KEY_F22] = C_GK_F22;
            arr[GLFW_KEY_F23] = C_GK_F23;
            arr[GLFW_KEY_F24] = C_GK_F24;
            arr[GLFW_KEY_F25] = C_GK_UNKNOWN;
            arr[96] = C_GK_NUMPAD0;
            arr[97] = C_GK_NUMPAD1;
            arr[98] = C_GK_NUMPAD2;
            arr[99] = C_GK_NUMPAD3;
            arr[100] = C_GK_NUMPAD4;
            arr[101] = C_GK_NUMPAD5;
            arr[102] = C_GK_NUMPAD6;
            arr[103] = C_GK_NUMPAD7;
            arr[104] = C_GK_NUMPAD8;
            arr[105] = C_GK_NUMPAD9;
            arr[GLFW_KEY_KP_DECIMAL] = C_GK_DECIMAL;
            arr[GLFW_KEY_KP_DIVIDE] = C_GK_DIVIDE;
            arr[GLFW_KEY_KP_MULTIPLY] = C_GK_MULTIPLY;
            arr[GLFW_KEY_KP_SUBTRACT] = C_GK_SUBTRACT;
            arr[GLFW_KEY_KP_ADD] = C_GK_ADD;
            arr[GLFW_KEY_KP_ENTER] = C_GK_RETURN;
            arr[GLFW_KEY_KP_EQUAL] = C_GK_OEM_PLUS;
            arr[GLFW_KEY_LEFT_SHIFT] = C_GK_SHIFT;
            arr[GLFW_KEY_LEFT_CONTROL] = C_GK_CONTROL;
            arr[GLFW_KEY_LEFT_ALT] = C_GK_MENU;
            arr[GLFW_KEY_LEFT_SUPER] = C_GK_LWIN;
            arr[GLFW_KEY_RIGHT_SHIFT] = C_GK_SHIFT;
            arr[GLFW_KEY_RIGHT_CONTROL] = C_GK_CONTROL;
            arr[GLFW_KEY_RIGHT_ALT] = C_GK_MENU;
            arr[GLFW_KEY_RIGHT_SUPER] = C_GK_RWIN;
            arr[GLFW_KEY_MENU] = C_GK_UNKNOWN;
        }

      public:
        constexpr int jsKeyCodeToUltraLightKeyCode(uint32_t key) const
        {
            return key < Size ? arr[key] : C_GK_UNKNOWN;
        }

      private:
        int arr[Size];
    };
} // namespace Keycodes
