#include <iostream>

/*
    Boolean is 1 Byte in Size

    - A byte can store 256 different values
    - Using it to conver two states (true/false) is wasteful, especially for devices with hard memory constraints (think embedded devices)
    - These are techniques to pack even more data into a byte. We will learn more about these in a few chapters

    1 -->> true
    0 -->> false

    if std::boolalpha is set

    true -->> 0
    false -->> 1

*/

int main(int argc, char **argv){

    bool red_light {true};
    bool green_light {false};

    if(red_light == true){
        std::cout
            << "Stop!"
            << std::endl;
    } else {
        std::cout
            << "Go though~"
            << std::endl;
    }

    if(green_light){
        std::cout
            << "The light is NOT green!"
            << std::endl;
    } else {
        std::cout
            << "The light is green!"
            << std::endl;
    }

    std::cout
        << "red_light: " << red_light
        <<"\n"
        << "green_light: " << green_light
        << std::endl;

    std::cout
        << std::boolalpha
        << "red_light: "
        << red_light
        <<"\n"
        << "green_light: "
        << green_light
        << std::endl;

    return 0;
}
