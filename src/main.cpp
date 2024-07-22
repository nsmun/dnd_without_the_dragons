#include <iostream>
#include <string>

void start(); // Declaration
int power(int base, int exponent);


int main() { // int functions returns integers
    /*
        This is a multi line comment
    */
    std::cout << "Welcome to D&D (without the dragons)\n" << std::endl; // To go to next line do "\n" or "std::endl"
    start();
    return 0;
}


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