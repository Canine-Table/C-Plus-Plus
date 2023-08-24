#include <iostream>
#include <string>
#include <iomanip>

/*
    std::string:
        - concatenation
        - search
        - copy
        - ...
*/

int main(int argc, char **argv){

    {
        std::string full_name {}; //  Initialize an empty string
        std::string planet {"Earth. Where the sky is blue sometimes."}; // Initialize with a string literal
        std::string perfered_planet {planet}; // Initialize with other existing string
        std::string message {"Hello there",5}; // Initialize with part of a string literal. Contains "Hello"
        std::string weird_message {8,'\n'}; // Initialize with mutiple copies of a char. Contains 5 newline escapes
        std::string greeting {"Hello World!"};
        std::string say_hello {greeting,5,6}; // Initialize with part of an existing string starting at index 5 taking 6 characters to the right starting from the starting index 5.

        for (char c : weird_message) std::cout << c;

        // Changing string at runtime
        perfered_planet += " " + greeting;

        std::cout
            << std::quoted(weird_message)
            << planet
            << "\n"
            << perfered_planet
            << "\n"
            << message
            << say_hello
            << std::endl;
    }

    {
        // Use a raw array
        const char *p_planet {"Earth. Where the sky is blue sometimes."};
        p_planet = "Earth. Where the sky is blue always.";
            std::cout
                << std::quoted(p_planet)
                << std::endl;

    }

    return 0;
}
