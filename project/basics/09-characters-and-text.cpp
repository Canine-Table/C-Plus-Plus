#include <iostream>

/*
    you can interpret char as a regular character or as its integer value
    ex. char character {65} and char character {'A'} are the same thing

    char takes one Byte in memory:
        2^8 = 256 different values (0-255)
*/

int main(int argc, char **argv){

    /*
        ASCII Encoding Tables

        - ASCII was among the first encodings to represent text in a comnputer
        - It falls short when it copmes to representing languages other than English and a few other western languages. Think Arabic, East Asian Languages like Japanese, Chinese, ...
        - There are better ways to represent text that means to be seen in different languages, one of the most common being Unicode
        - Unicode is a robust way to represent text in different languages for a computer
    */

    char character0 {65};
    char character1 {114};
    char character2 {114};
    char character3 {111};
    char character4 {119};
    char character5 {0};

    std::cout
        << character0
        << " is number "
        << static_cast<int>(character0)
        << "\n"
        << character1
        << " is number "
        << static_cast<int>(character1)
        << "\n"
        << character2
        << " is number "
        << static_cast<int>(character2)
        << "\n"
        << character3
        << " is number "
        << static_cast<int>(character3)
        << "\n"
        << character4
        << " is number "
        << static_cast<int>(character4)
        << "\n"
        << character5
        << " is number "
        << static_cast<int>(character5)
        << std::endl;

    return 0;
}
