/*
                     ColorCout
                     - ColorCout.hpp

               Version 1, April 2020
Copyright (C) 2020 GloomyGhost <GloomyGhost@foxmail.com>

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.
 */

#pragma once

#ifndef COLORBOX_COLORCOUT_H
#define COLORBOX_COLORCOUT_H

#include <iostream>

#ifdef WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#if MSVC
#define NOMINMAX
#endif
#include <Windows.h>
#include <wincon.h>

enum class cc : uint16_t {
      grey       = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
    , blue       = FOREGROUND_BLUE | FOREGROUND_INTENSITY
    , green      = FOREGROUND_GREEN | FOREGROUND_INTENSITY
    , cyan       = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
    , red        = FOREGROUND_RED | FOREGROUND_INTENSITY
    , magenta    = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY
    , yellow     = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
    , white      = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
    , on_blue    = BACKGROUND_BLUE
    , on_red     = BACKGROUND_RED
    , on_magenta = BACKGROUND_BLUE | BACKGROUND_RED
    , on_grey    = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED
    , on_green   = BACKGROUND_GREEN | BACKGROUND_INTENSITY
    , on_cyan    = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY
    , on_yellow  = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY
    , on_white   = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY
    , reset
    };
#else
enum class cc : uint8_t {
    grey = 30, red = 31, green = 32, yellow = 33,
    blue = 34, magenta = 35, cyan = 36, white = 37,
    on_grey = 40, on_red = 41, on_green = 42, on_yellow = 43,
    on_blue = 44, on_magenta = 45, on_cyan = 46, on_white = 47,
    reset
};
#endif

template<typename type>
type &operator<<(type &ostream, const cc color) {
#ifdef WIN32
    static const uint16_t initial_attributes = [] {
        CONSOLE_SCREEN_BUFFER_INFO buffer_info;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffer_info);
        return buffer_info.wAttributes;
    }();
    static uint16_t background = initial_attributes & 0x00F0;
    static uint16_t foreground = initial_attributes & 0x000F;
#endif
    if (color == cc::reset) {
#ifdef WIN32
        ostream.flush();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), initial_attributes);
#else
        ostream << "\033[m";
#endif
    } else {
#ifdef WIN32
        uint16_t set = 0;
        if (static_cast<uint16_t>(color) & 0x00F0) {
            background = static_cast<uint16_t>(color);
            set = background | foreground;
        }
        else if (static_cast<uint16_t>(color) & 0x000F) {
            foreground = static_cast<uint16_t>(color);
            set = background | foreground;
        }
        ostream.flush();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), set);
#else
        ostream << "\033[" << static_cast<uint32_t>(color) << "m";
#endif
    }
    return ostream;
}

#endif //COLORBOX_COLORCOUT_H
