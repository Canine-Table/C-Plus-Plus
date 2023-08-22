#include <iostream>

/*
    Can use normal pointer to char like we've been doing so for double, int, bool, and anything else really.
    But pointers to char can do something special.
    You can initialize with a string literal: C-String
*/

int main(int argc, char **argv){
    char *p_char {nullptr};

    // this will compile with a  warning: ISO C++ forbids converting a string constant to 'char*'
    char *p_message {"Hello World!"};
    char char_var {'A'};

    // this is a character pointer array of const char
    p_char = &char_var;

    // What do we get if we dereference the pointer??
    std::cout
        << "The *p_char pointer is pointing to: "
        << p_char
        << "\n"
        << "The value stored in *p_char is: "
        << *p_char
        << "\n"
        << "The value stored in p_message is: "
        << p_message
        << "\n"
        << "The value stored in *p_message is: "
        << *p_message
        << "\n"
        << std::endl;

    /*
        The string literal p_message is made up of const char.
        Trying to modify any of them will result in a disaster

        DON'T:
            *p_message = 'B';   We want the message Bello World
            we will get a compiler error not just a warning

        DO:
            char message2[] {"Hello World"};  initialize a char array
            message2[0] = 'B';
            char *p_message2 = &message2

            or

            const char *p_message2 {"Bello World"};

                We will get the message Bello World without errors or warnings.
    */

    const char *p_message2 {"Bello World"};
    std::cout
        << "The p_message2 pointer is pointing to: "
        << p_message2
        << "\n"
        << "The *p_message2 pointer is pointing to: "
        << *p_message2
        << "\n"
        << std::endl;

    return 0;
}
