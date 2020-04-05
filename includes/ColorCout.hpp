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
#ifndef COLORCOUT_H
#define COLORCOUT_H

#if WIN32

#include <Windows.h>

#define ccout(COLOR) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR); std::cout
#define ccend "";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT)
#define ccendl std::endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT)

#define DEFAULT         15
#define BLACK           0
#define DARK_BLUE       1
#define DARK_GREEN      2
#define DARK_CYAN       3
#define DARK_RED        4
#define DARK_MAGENTA    5
#define BROWN           6
#define GRAY            8
#define BLUE            9
#define GREEN           10
#define CYAN            11
#define RED             12
#define MAGENTA         13
#define YELLOW          14
#define WHITE           15

#else

#define ccout(COLOR) std::cout << COLOR << "m"
#define ccend DEFAULT << "m"
#define ccendl DEFAULT << "m" << std::endl


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

#endif