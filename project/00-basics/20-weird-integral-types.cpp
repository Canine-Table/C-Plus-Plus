#include <iostream>

/*
    Integral types less than 4 bytes do not support arithmetic operations

    ex. char
    ex. short int

    int is the smallest type for arithmetic operations therefore these values will be transformed implicitly to int behind the scenes by the procesor

    The same behavior is present on other operators like bitwise shirt operators (>> and <<).
*/

int main(int argc, char **argv){

    short int var1 {10}; // 2 bytes

    char var2 {30}; // 1 byte

    auto result1 = var1 + var1; // 4 bytes
    auto result2 = var2 + var2; // 4 bytes

    std::cout
        << "\n"
        << "size of <short int> var1 {10}; in bytes is: "
        << sizeof(var1)
        << "\n"
        << "size of <char> var2 {30}; in bytes is: "
        << sizeof(var2)
        << "\n"
        << "size of var1 + var1 is: "
        << sizeof(result1)
        << "\n"
        << "size of var2 + var2 is: "
        << sizeof(result2)
        << "\n"
        << std::endl;

    return 0;
}
