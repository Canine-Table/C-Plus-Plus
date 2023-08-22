#include <iostream>

int main(int argc, char **argv){

    int numbers[] {1,2,3,4,5,6,7,8,9,0};

    // Reading beond bound will return a garbage value, crash your program
    std::cout
        << "out of bounds: "
        << numbers[54]
        << std::endl;

    /*
        Writing out of bounds is even worse. the compiler allows it but you don't own the memory at index 54.
        Best case, other programs which own that memory will modify it and your program may read bogus data at a later time.
        Worst case you could crash an unrelated program or even your operating system.
        C++ compilers expect you to know what your doing so DON'T GO OUT OF BOUNDS!!!

        DANGER:
        numbers[54] = 1000;
    */

    return 0;
}
