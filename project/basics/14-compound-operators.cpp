#include <iostream>

int main(int argc, char **argv){
    int value {0};

    value -= 5;
    std::cout << value << "\n"; // -5

    value += 50;
    std::cout << value << "\n"; // 45

    value *= 5;
    std::cout << value << "\n"; // 225

    value /= 2;
    std::cout << value << "\n"; // 112

    value %= 3;
    std::cout << value << std::endl; // 1

    return 0;
}
