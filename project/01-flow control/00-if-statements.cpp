#include <iostream>

int main(int argc, char **argv){

    int num1 {55};
    int num2 {60};

        std::cout
            << "\n"
            << "num1: "
            << num1
            << "\n"
            << "num2: "
            << num2
            << "\n"
            << std::endl;

    if (num1 < num2) {

        std::cout
            << "num1 is smaller than num2"
            << std::endl;

    } else if (num1 > num2) {

        std::cout
            << "num1 is larger than num2"
            << std::endl;

    } else {

        std::cout
            << "num1 and num2 are equal"
            << std::endl;
    }

    return 0;
}
