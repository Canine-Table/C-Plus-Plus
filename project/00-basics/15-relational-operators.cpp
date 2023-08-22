#include <iostream>

int main(int argc, char **argv){

    int value_one {45};
    int value_two {60};

    std::cout
        << std::boolalpha // changes 0 and 1 to true or false
        << "\n"
        << "value 1: "
        << value_one
        << "\n"
        << "value 2: "
        << value_two
        << "\n-----------\n\n"
        << "value 1 > value 2: "
        << (value_one > value_two)
        << "\n"
        << "value 1 < value 2: "
        << (value_one < value_two)
        << "\n"
        << "value 1 >= value 2: "
        << (value_one >= value_two)
        << "\n"
        << "value 1 <= value 2: "
        << (value_one <= value_two)
        << "\n"
        << "value 1 == value 2: "
        << (value_one == value_two)
        << "\n"
        << "value 1 != value 2: "
        << (value_one != value_two)
        << "\n"
        << std::endl;

    return 0;
}
