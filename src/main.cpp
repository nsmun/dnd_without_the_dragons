#include "include.h"
#include "csvparser.h"

int main() { // int functions returns integers
    /*
        This is a multi line comment
    */
    std::cout << "Welcome to D&D (without the dragons)\n" << std::endl; // To go to next line do "\n" or "std::endl"

    Spreadsheet myspreadcheek("items.csv");

    std::cout << myspreadcheek.get_cell(0, 0) << std::endl;
    std::cout << myspreadcheek.get_cell(-1, 0) << std::endl;
    std::cout << myspreadcheek.get_cell(0, -1) << std::endl;
    std::cout << myspreadcheek.get_cell(1110, 110) << std::endl;
    std::cout << myspreadcheek.get_cell("name", 0) << std::endl;
    std::cout << myspreadcheek.get_cell("stat", 0) << std::endl;
    std::cout << myspreadcheek.get_cell("ppppppp", 0) << std::endl;


    return 0;
}



















/*
void start() { // Definition
    std::string newvar = "testing";
    std::cout << newvar << std::endl;
    std::cout << power(21, 4) << std::endl;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
*/