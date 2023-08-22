#include <iostream>

int main(int argc, char **argv){

    int num1 {5};
    int num2 {54};
    bool fast {true};
    int speed {fast ? 300 : 150};
    std::string result = (num1 > num2) ? "num1 is larger than num2" : "num2 is larger than num1";

    std::cout
        << "num1: "
        << num1
        << "\n"
        << "num2: "
        << num2
        << "\n"
        << result
        << "\n"
        << "speed: "
        << speed
        << "km/h"
        << std::endl;

    return 0;

}
