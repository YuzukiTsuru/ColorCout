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

#if WIN32

#include <Windows.h>

#define ccout(a) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a); std::cout
#define cend SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#define cendl std::endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

#define DEFAULT         15
#define BLACK           0
#define BLUE            1
#define GREEN           2
#define CYAN            3
#define RED             4
#define MAGENTA         5
#define BROWN           6
#define LIGHTGRAY       7
#define DARKGRAY        8
#define LIGHTBLUE       9
#define LIGHTGREEN      10
#define LIGHTCYAN       11
#define LIGHTRED        12
#define LIGHTMAGENTA    13
#define YELLOW          14
#define WHITE           15

#else

#define ccout(a) std::cout << a << "m"
#define cend DEFAULT << "m"
#define cendl DEFAULT << "m" << std::endl


#define DEFAULT         "\033["
#define BLACK           "\033[30"
#define GREY            "\033[1;30"
#define DARK_RED        "\033[31"
#define RED             "\033[1;31"
#define DARK_GREEN      "\033[32"
#define GREEN           "\033[1;32"
#define DARK_YELLOW     "\033[33"
#define YELLOW          "\033[1;33"
#define DARK_BLUE       "\033[34"
#define BLUE            "\033[1;34"
#define DARK_MAGENTA    "\033[35"
#define MAGENTA         "\033[1;35"
#define DARK_CYAN       "\033[36"
#define CYAN            "\033[1;36"
#define LIGHT_GREY      "\033[37"
#define WHITE           "\033[1;37"
#endif