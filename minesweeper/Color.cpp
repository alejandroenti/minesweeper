#include "Color.h"

void color(std::string color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col = 7;

    if (color == "blue") col = 1;
    else if (color == "green") col = 2;
    else if (color == "cyan") col = 3;
    else if (color == "red") col = 4;
    else if (color == "magenta") col = 5;
    else if (color == "yellow") col = 6;

    SetConsoleTextAttribute(hConsole, col);
}