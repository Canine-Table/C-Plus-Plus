#include <iostream>

/*
    Runs the body then checks
*/

int main(int argc, char **argv){

    size_t count {11};

    while (--count) {
        std::cout
            << "I love C++ with a rank of "
            << count
            << " / 10"
            << "\n";
    }

    std::cout << "\nloops are done.\n" << std::endl;

    return 0;
}
