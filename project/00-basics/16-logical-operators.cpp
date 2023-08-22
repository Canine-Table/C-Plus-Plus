#include <iostream>

/*
    AND:    &&
    OR:     ||
    NOT:    !
*/

int main(int argc, char **argv){

    bool value_one {false};
    bool value_two {true};

    std::cout
        << std::boolalpha // changes 0 and 1 to true or false
        << "\n"
        << "value 1: "
        << value_one
        << "\n"
        << "value 2: "
        << value_two
        << "\n-----------\n\n"
        << "value 1 && value 2: "
        << (value_one && value_two)
        << "\n"
        << "value 1 || value 2: "
        << (value_one || value_two)
        << "\n"
        << "! value 1 && value 2: "
        << (! value_one && value_two)
        << "\n"
        << "value 1 || ! value 2: "
        << (value_one || ! value_two)
        << std::endl;

    return 0;
}
