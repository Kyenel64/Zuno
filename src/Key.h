// --- Key.h ---
// Created by Kye Nelson on 6/23/25.
// Keycodes and scancodes. Equivalent to SDL key mappings.
#pragma once

namespace Zuno
{
    // Key scancode
    typedef enum KeyCode
    {
        UNKNOWN = 0,

        KEY_A = 4,
        KEY_B = 5,
        KEY_C = 6,
        KEY_D = 7,
        KEY_E = 8,
        KEY_F = 9,
        KEY_G = 10,
        KEY_H = 11,
        KEY_I = 12,
        KEY_J = 13,
        KEY_K = 14,
        KEY_L = 15,
        KEY_M = 16,
        KEY_N = 17,
        KEY_O = 18,
        KEY_P = 19,
        KEY_Q = 20,
        KEY_R = 21,
        KEY_S = 22,
        KEY_T = 23,
        KEY_U = 24,
        KEY_V = 25,
        KEY_W = 26,
        KEY_X = 27,
        KEY_Y = 28,
        KEY_Z = 29,

        KEY_1 = 30,
        KEY_2 = 31,
        KEY_3 = 32,
        KEY_4 = 33,
        KEY_5 = 34,
        KEY_6 = 35,
        KEY_7 = 36,
        KEY_8 = 37,
        KEY_9 = 38,
        KEY_0 = 39,

        KEY_RETURN = 40,
        KEY_ESCAPE = 41,
        KEY_BACKSPACE = 42,
        KEY_TAB = 43,
        KEY_SPACE = 44,

        KEY_MINUS = 45,
        KEY_EQUALS = 46,
        KEY_LEFTBRACKET = 47,
        KEY_RIGHTBRACKET = 48,
        KEY_BACKSLASH = 49,
        KEY_NONUSHASH = 50,
        KEY_SEMICOLON = 51,
        KEY_APOSTROPHE = 52,
        KEY_GRAVE = 53,
        KEY_COMMA = 54,
        KEY_PERIOD = 55,
        KEY_SLASH = 56,

        KEY_CAPSLOCK = 57,

        KEY_F1 = 58,
        KEY_F2 = 59,
        KEY_F3 = 60,
        KEY_F4 = 61,
        KEY_F5 = 62,
        KEY_F6 = 63,
        KEY_F7 = 64,
        KEY_F8 = 65,
        KEY_F9 = 66,
        KEY_F10 = 67,
        KEY_F11 = 68,
        KEY_F12 = 69,

        KEY_PRINTSCREEN = 70,
        KEY_SCROLLLOCK = 71,
        KEY_PAUSE = 72,
        KEY_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                       does send code 73, not 117) */
        KEY_HOME = 74,
        KEY_PAGEUP = 75,
        KEY_DELETE = 76,
        KEY_END = 77,
        KEY_PAGEDOWN = 78,
        KEY_RIGHT = 79,
        KEY_LEFT = 80,
        KEY_DOWN = 81,
        KEY_UP = 82,

        KEY_NUMLOCKCLEAR = 83,

        KEY_KP_DIVIDE = 84,
        KEY_KP_MULTIPLY = 85,
        KEY_KP_MINUS = 86,
        KEY_KP_PLUS = 87,
        KEY_KP_ENTER = 88,
        KEY_KP_1 = 89,
        KEY_KP_2 = 90,
        KEY_KP_3 = 91,
        KEY_KP_4 = 92,
        KEY_KP_5 = 93,
        KEY_KP_6 = 94,
        KEY_KP_7 = 95,
        KEY_KP_8 = 96,
        KEY_KP_9 = 97,
        KEY_KP_0 = 98,
        KEY_KP_PERIOD = 99,

        KEY_NONUSBACKSLASH = 100,
        KEY_APPLICATION = 101,
        KEY_POWER = 102,
        KEY_KP_EQUALS = 103,
        KEY_F13 = 104,
        KEY_F14 = 105,
        KEY_F15 = 106,
        KEY_F16 = 107,
        KEY_F17 = 108,
        KEY_F18 = 109,
        KEY_F19 = 110,
        KEY_F20 = 111,
        KEY_F21 = 112,
        KEY_F22 = 113,
        KEY_F23 = 114,
        KEY_F24 = 115,
        KEY_EXECUTE = 116,
        KEY_HELP = 117,
        KEY_MENU = 118,
        KEY_SELECT = 119,
        KEY_STOP = 120,
        KEY_AGAIN = 121,
        KEY_UNDO = 122,
        KEY_CUT = 123,
        KEY_COPY = 124,
        KEY_PASTE = 125,
        KEY_FIND = 126,
        KEY_MUTE = 127,
        KEY_VOLUMEUP = 128,
        KEY_VOLUMEDOWN = 129,
        KEY_LOCKINGCAPSLOCK = 130,
        KEY_LOCKINGNUMLOCK = 131,
        KEY_LOCKINGSCROLLLOCK = 132,
        KEY_KP_COMMA = 133,
        KEY_KP_EQUALSAS400 = 134,

        KEY_INTERNATIONAL1 = 135,
        KEY_INTERNATIONAL2 = 136,
        KEY_INTERNATIONAL3 = 137,
        KEY_INTERNATIONAL4 = 138,
        KEY_INTERNATIONAL5 = 139,
        KEY_INTERNATIONAL6 = 140,
        KEY_INTERNATIONAL7 = 141,
        KEY_INTERNATIONAL8 = 142,
        KEY_INTERNATIONAL9 = 143,
        KEY_LANG1 = 144,
        KEY_LANG2 = 145,
        KEY_LANG3 = 146,
        KEY_LANG4 = 147,
        KEY_LANG5 = 148,
        KEY_LANG6 = 149,
        KEY_LANG7 = 150,
        KEY_LANG8 = 151,
        KEY_LANG9 = 152,

        KEY_ALTERASE = 153,
        KEY_SYSREQ = 154,
        KEY_CANCEL = 155,
        KEY_CLEAR = 156,
        KEY_PRIOR = 157,
        KEY_RETURN2 = 158,
        KEY_SEPARATOR = 159,
        KEY_OUT = 160,
        KEY_OPER = 161,
        KEY_CLEARAGAIN = 162,
        KEY_CRSEL = 163,
        KEY_EXSEL = 164,

        KEY_KP_00 = 176,
        KEY_KP_000 = 177,
        KEY_THOUSANDSSEPARATOR = 178,
        KEY_DECIMALSEPARATOR = 179,
        KEY_CURRENCYUNIT = 180,
        KEY_CURRENCYSUBUNIT = 181,
        KEY_KP_LEFTPAREN = 182,
        KEY_KP_RIGHTPAREN = 183,
        KEY_KP_LEFTBRACE = 184,
        KEY_KP_RIGHTBRACE = 185,
        KEY_KP_TAB = 186,
        KEY_KP_BACKSPACE = 187,
        KEY_KP_A = 188,
        KEY_KP_B = 189,
        KEY_KP_C = 190,
        KEY_KP_D = 191,
        KEY_KP_E = 192,
        KEY_KP_F = 193,
        KEY_KP_XOR = 194,
        KEY_KP_POWER = 195,
        KEY_KP_PERCENT = 196,
        KEY_KP_LESS = 197,
        KEY_KP_GREATER = 198,
        KEY_KP_AMPERSAND = 199,
        KEY_KP_DBLAMPERSAND = 200,
        KEY_KP_VERTICALBAR = 201,
        KEY_KP_DBLVERTICALBAR = 202,
        KEY_KP_COLON = 203,
        KEY_KP_HASH = 204,
        KEY_KP_SPACE = 205,
        KEY_KP_AT = 206,
        KEY_KP_EXCLAM = 207,
        KEY_KP_MEMSTORE = 208,
        KEY_KP_MEMRECALL = 209,
        KEY_KP_MEMCLEAR = 210,
        KEY_KP_MEMADD = 211,
        KEY_KP_MEMSUBTRACT = 212,
        KEY_KP_MEMMULTIPLY = 213,
        KEY_KP_MEMDIVIDE = 214,
        KEY_KP_PLUSMINUS = 215,
        KEY_KP_CLEAR = 216,
        KEY_KP_CLEARENTRY = 217,
        KEY_KP_BINARY = 218,
        KEY_KP_OCTAL = 219,
        KEY_KP_DECIMAL = 220,
        KEY_KP_HEXADECIMAL = 221,

        KEY_LCTRL = 224,
        KEY_LSHIFT = 225,
        KEY_LALT = 226,
        KEY_LGUI = 227,
        KEY_RCTRL = 228,
        KEY_RSHIFT = 229,
        KEY_RALT = 230,
        KEY_RGUI = 231,

        KEY_MODE = 257,

        KEY_SLEEP = 258,
        KEY_WAKE = 259,

        KEY_INCREMENT = 260,
        KEY_DECREMENT = 261,

        KEY_MEDIA_PLAY = 262,          /**< Play */
        KEY_MEDIA_PAUSE = 263,         /**< Pause */
        KEY_MEDIA_RECORD = 264,        /**< Record */
        KEY_MEDIA_FAST_FORWARD = 265,  /**< Fast Forward */
        KEY_MEDIA_REWIND = 266,        /**< Rewind */
        KEY_MEDIA_NEXT_TRACK = 267,    /**< Next Track */
        KEY_MEDIA_PREVIOUS_TRACK = 268, /**< Previous Track */
        KEY_MEDIA_STOP = 269,          /**< Stop */
        KEY_MEDIA_EJECT = 270,         /**< Eject */
        KEY_MEDIA_PLAY_PAUSE = 271,    /**< Play / Pause */
        KEY_MEDIA_SELECT = 272,        /* Media Select */

        KEY_AC_NEW = 273,              /**< AC New */
        KEY_AC_OPEN = 274,             /**< AC Open */
        KEY_AC_CLOSE = 275,            /**< AC Close */
        KEY_AC_EXIT = 276,             /**< AC Exit */
        KEY_AC_SAVE = 277,             /**< AC Save */
        KEY_AC_PRINT = 278,            /**< AC Print */
        KEY_AC_PROPERTIES = 279,       /**< AC Properties */

        KEY_AC_SEARCH = 280,           /**< AC Search */
        KEY_AC_HOME = 281,             /**< AC Home */
        KEY_AC_BACK = 282,             /**< AC Back */
        KEY_AC_FORWARD = 283,          /**< AC Forward */
        KEY_AC_STOP = 284,             /**< AC Stop */
        KEY_AC_REFRESH = 285,          /**< AC Refresh */
        KEY_AC_BOOKMARKS = 286,        /**< AC Bookmarks */

        KEY_SOFTLEFT = 287, /**< Usually situated below the display on phones and
                                          used as a multi-function feature key for selecting
                                          a software defined function shown on the bottom left
                                          of the display. */
        KEY_SOFTRIGHT = 288, /**< Usually situated below the display on phones and
                                           used as a multi-function feature key for selecting
                                           a software defined function shown on the bottom right
                                           of the display. */
        KEY_CALL = 289, /**< Used for accepting phone calls. */
        KEY_ENDCALL = 290, /**< Used for rejecting phone calls. */

        /* @} *//* Mobile keys */

        /* Add any other keys here. */

        KEY_RESERVED = 400,    /**< 400-500 reserved for dynamic keycodes */

        KEY_COUNT = 512 /**< not a key, just marks the number of scancodes for array bounds */
    } KeyCode;
}
