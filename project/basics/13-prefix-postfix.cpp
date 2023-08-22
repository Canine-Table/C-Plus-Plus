#include <iostream>

/*
    prefix and postfix increment/decrement operators are cool!

    There are no value** or **value, value// or //value. they do not make sense, these prefix/postfix operators are only avalible for + and - operators.
*/

int main(int argc, char **argv){
    int value {0};

    std::cout
        << value++
        << "\n"
        << value
        << "\n"
        << ++value
        << "\n"
        << --value
        << "\n"
        << --value
        << std::endl;

    return 0;
}
