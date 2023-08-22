#include <iostream>
#include <cmath>

// size() was added in C++17

int main(int argc, char **argv){
    char grades[] {'A','B','C','D','B','F','A','C','A','C'};
        for (size_t i{}; i < std::size(grades); i++) {
        std::cout
            << i
            << ") "
            << grades[i]
            << std::endl;
    }

    std::cout
        << "\n--------\n"
        << std::endl;

    // before C++17 to get the size of an array was as follows
    for (size_t i{}; i < sizeof(grades) / sizeof(grades[0]); i++) {
    std::cout
        << i
        << ") "
        << grades[i]
        << std::endl;
    }

    return 0;
}
