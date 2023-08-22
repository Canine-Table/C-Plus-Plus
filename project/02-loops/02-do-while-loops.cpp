#include <iostream>

int main(int argc, char **argv){

    size_t count {10};

    do {
        std::cout
            << "I love C++ with a rank of "
            << count
            << " / 10"
            << "\n";
    } while (--count);

    std::cout << "\nloops are done.\n" << std::endl;

    return 0;
}
