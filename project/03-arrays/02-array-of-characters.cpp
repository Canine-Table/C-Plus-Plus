#include <iostream>
#include <iomanip>

int main(int argc, char **argv){
    // \0 is a null termination character
    char message1[] {'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};

    // this will happen if the size is specified and all slots are filled without one being a null character \0.
    // Hello World!Hello World!
    char message2[12] {'H','e','l','l','o',' ','W','o','r','l','d','!'};

    // this has 13 characters with 1 not filled, this is ok
    char message3[13] {'H','e','l','l','o',' ','W','o','r','l','d','!'};

    // this is also valid using string literals. this will declare a char array with a trailing \0
    char message4[] {"Hello World!"};

    std::cout
        << std::left // left justified
        << "\n"
        << std::setw(35)
        << "Message"
        << "Bytes"
        << "\n"
        << std::setw(35)
        << message1
        << sizeof(message1)
        << "\n"
        << std::setw(35)
        << message2
        << sizeof(message2)
        << "\n"
        << std::setw(35)
        << message3
        << sizeof(message4)
        << "\n"
        << std::setw(35)
        << message4
        << sizeof(message4)
        << std::endl;

    return 0;
}
