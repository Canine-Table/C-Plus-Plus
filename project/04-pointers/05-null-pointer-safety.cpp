#include <iostream>

/*
    Making sure you are working with valid pointers containing valid memory addresses
*/

int main(int argc, char **argv){
    int *p_int1;  // initialized to nullptr
    int *p_int2 {}; // initialized to nullptr
    int *p_int3 {nullptr};  // initialized to nullptr
    int *p_int4 {new int {45}};
    int int5 {53};
    int *p_int5 = &int5;

    // you can delete a pointer with the value nullptr, that is valid C++ code, you will not get any errors.

    if (p_int5 != nullptr) {

        std::cout
            << "points to a VALID address"
            << std::endl;

    } else {

        std::cout
            << "points to a INVALID address"
            << std::endl;

    }
    return 0;
}
