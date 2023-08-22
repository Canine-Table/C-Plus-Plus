#include <iostream>

/*
    Pilars of any loop

        - Iterator
        - Starting Point
        - Test(Controls when the loop stops)
        - Increment(Decrement)
        - Loop Body

    size_t:
        size in bytes in memory: 8
        Not a type, just a type alias for some unsigned int representation


    if you try try to access variable i outside the loop you will get a compiler error stating i does not exsist in the main function local scope

    if you declare i before hand in the global scope of main you can do something like this:

        side_t i{};
        for( ; j < 10; j++){
            ...
        }

    You will be able to access i outside of the local iterator scope of the for loop if is declared beforehand in the global scope

    DONT HARD CODE VALUES! This is better design:

        const size_t COUNT {10};
        for(size_t i; j < COUNT; j++){
            ...
        }
*/

int main(int argc, char **argv){


    const size_t COUNT {10};

    for (size_t i{}; i < COUNT; i++){
        std::cout
            << "I love C++ with a rank of "
            << i
            << " / 10"
            << "\n";
    }


    for (unsigned int i{10}; i > 0; i--) {
        std::cout
            << "I love C++ with a rank of "
            << i
            << " / 10"
            << "\n";
    }

    std::cout << "loops are done." << std::endl;

    return 0;
}
