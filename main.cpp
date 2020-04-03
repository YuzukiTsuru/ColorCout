#include <iostream>
#include "includes/ColorCout.hpp"

int main() {
    ccout(YELLOW) << "Hello, World!" << ccendl;
    ccout(CYAN) << "Hello, World!" << ccend;
    ccout(WHITE) << "Hello, World!" << ccendl;
    return 0;
}
