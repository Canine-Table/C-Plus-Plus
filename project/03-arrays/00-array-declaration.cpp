#include <iostream>
#include <cmath>

/*
    Arrays store values of the same type. mixing type will result in a compiler error.

    if you don't initialize all the elements those you leave  will be initialized to 0

        int numbers[5] {1,2,3};

    numbers will hold 1,2,3,0,0
    it it also possible to omit the size of the array at declaration and will deduce the size from the elements in the array
        int numbers[] {1,2,3}; is the same as int numbers[3] {1,2,3};

        this is not valid C++:
            int numbers[];
        if you dont declare values for the array you must declare the size
        this is valid C++:
            int numbers[3]; is valid C++

    it is also possible to make your array constant, can't be changed
        const int numbers[] {1,2,3};
        numbers[1] = 4; can't change elements of a const array: ERROR

    the const keyword also applies to non array variables.
*/

int main(int argc, char **argv){
    char grades[10] {'A','B','C','D','B','F','A','C','A','C'};
    size_t cubed[12];

    for (size_t i{}; i < 10; i++) {
        std::cout
            << i
            << ") "
            << grades[i]
            << std::endl;
    }

    std::cout
        << "--------------------------\n\n"
        << std::endl;

    for (size_t i{}; i < 12; i++) {
        cubed[i] = std::pow(i,3);
        std::cout
            << i
            << " * "
            << 3
            << " = "
            << cubed[i]
            << "\n"
            << std::endl;
    }

    std::cout
        << "--------------------------\n\n"
        << std::endl;

    // this is a ranged based for loop
    for (auto value : cubed) {
        std::cout
            << std::sqrt(value)
            << "\n"
            << std::endl;

    }

    return 0;
}
