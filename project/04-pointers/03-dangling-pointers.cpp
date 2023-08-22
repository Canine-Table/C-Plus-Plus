#include <iostream>

/*
    A dangling pointer is a pointer that does not point to a valid memory address.
    Trying to dereference and use a dangling pointer will result in undefined behavior.

    The dangling pointers we will be looking at are:

        - Uninitialized Pointers
        - Deleted Pointers
        - Multiple Pointers pointing to the same memory address
*/

int main(int argc, char **argv){

    int *uninitialized_dangling_pointer; // Case 1:  this points no where, do not dereference this type of pointer
    int *deleted_pointer {new int {43}};
    delete deleted_pointer; // Case 2:  this pointer is avalible for reinitializing, do not dereference this pointer until you have reinitiated it.
    uninitialized_dangling_pointer = nullptr;
    deleted_pointer = nullptr;

    if (deleted_pointer == nullptr){
        std::cerr
            << "pointer must be reinitialized"
            << std::endl;
    } else {
        std::cout
            << "your all set, the pointer has been initialized"
            << std::endl;
    }

    int *p_duplicate {new int {34}}; // initializing dynamic memory using the braced intitializer
    int *p_duplicate_pointer {p_duplicate}; // Points to p_duplicate allocated memory
    delete p_duplicate_pointer; /* Case 3
        p_duplicate now points to a deleted memory address.
        Dereferncing it will lead to undefined behavior:
            - Crash
            - Garbage
            - Computer explodes in a ball of fire!

        These are some real problems with no solutions!
        Just kidding some solutions are:
            - Initialize your pointers
            - Reset pointers after deletion to nullptr
            - For mutiple pointers to the same address, make sure the master pointer is very clear, the rest are slave pointers
    */

    p_duplicate = nullptr;
    p_duplicate_pointer = nullptr;

    return 0;
}
