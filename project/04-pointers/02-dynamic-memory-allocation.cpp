# include <iostream>

/*
    INFO:
        The star at the beginning of a pointer is called the dereference operator

    It's a bad idea to use pointers which are not initialized.
    lets say you create but dont initialize a pointer called:

        int *p_pointer;

    the *p_pointer has not been initialized so lets try and do the following:

        *p_pointer = {53};

    since the *p_pointer was never initialized it will contain any memory address posssible.
    This memory address could belong to another program or even the operating system, its not your address to mess with.
    doing *p_pointer = {53}; we are actually tying to mess with memory address that is not ours by changing the value to 55.
    This could crash applications or even corrupt data used by the system or even other people.

    C++ calls this undefined behavior so initialize your pointers before you use them for the love of C++

    its best practice to always initialize your pointers by doing either of the following:

        int *p_pointer = {};

    or:

        int *p_pointer = {nullptr};

    both these method are valid for initializing your pointers so the above senario does not occur.


    So far we have only been using memory allocated on the stack.
    We are going to see how one can allocate memory from the heap, and some of the differences between these mechanisms.
*/

int main(int argc, char **argv){

    // this is a global scope of int main

    int num {343};
    int *p_int3 = &num; // this will alocate 4 bytes in the stack

    int *p_int4 {nullptr}, *p_int5 {new int};

    // *p_int5     memory location contains junk value

    { // this is a local scope
        p_int4 = new int; // we have now allocated 4 bytes for this int pointer on the heap
        *p_int4 = 77; // This is not stored on the stack, this is now stored on the 4 bytes allocated on the heap

        {
            /*
                this is a local scope of a local scope

                it is possible to initialize the pointer with a valid address up on declaration.
                Not just with nullptr.
            */

                int *p_int6 {new int (22)}, *p_int7 {new int { 23}};

                /*
                    *p_int6     use direct initialization
                    *p_int7     use uniform initialization
                */

            std::cout
                << "*p_int6 value: "
                << *p_int6
                << "\n"
                << "p_int6 location: "
                << p_int6
                << "\n"
                << "*p_int7 value: "
                << *p_int7
                << "\n"
                << "p_int7 location: "
                << p_int7
                << "\n"
                << std::endl;

            /*
                NOTE:

                    it is REALLY BAD to call delete twice on an a pointer for example:

                        delete p_int6;
                        delete p_int6;

                    Calling delete on a pointer twice will lead to undefined behavior.
                    Your program may even crash!
                    Avoid this like the Plage!

                    NOTE:
                        Most operating systems will view this as a rogue program which will result in the program being  killed.
            */

            delete p_int6;
            p_int6 = nullptr;

            delete p_int7;
            p_int7 = nullptr;
        }
    }

    std::cout
        << "*p_int3 value: "
        << *p_int3
        << "\n"
        << "p_int3 location: "
        << p_int3
        << "\n"
        << "*p_int4 value: "
        << *p_int4
        << "\n"
        << "p_int4 location: "
        << p_int4
        << "\n"
        << "*p_int5 value: "
        << *p_int5
        << "\n"
        << "p_int5 location: "
        << p_int5
        << "\n"
        << std::endl;

        p_int3 = nullptr;
    /*
        Dynamiclly allocate space for a single int on the heap.
        This memory belongs to our program from now on.
        The system can;t use it for anything else, until we return it.
        After this line executes, we will have a valid memory location allocated.
        The size of the allocated memory will be such that it can store the type pointed to the pointer
    */

    { // this is a local scope
        delete p_int4;
        p_int4 = nullptr; // make sure when you release memory to also reset it with nullptr so we dont run into the problem mentioned above.

        delete p_int5;
        p_int5 = nullptr;

        /*
            These pointers are not deleted, they can be reused to allocate new memory on the heap which will point to NEW MEMORY locations on the heap.
        */
    }

    std::cout
        << "p_int4 location: "
        << p_int4
        << "\n"
        << "*p_int4 value: "
        << *p_int4
        << std::endl;

    return 0;
}
