#include <iostream>

/*
    pointers are declared with a star after the type

    Don't use pointers to nullptr

    all pointers are of the same size on the same system mine being 8 bytes in size.

    it is adviced to alway initialize your pointers with either {}; or explicitely like {nullptr};
*/

int main(int argc, char **argv){

    // Explicitely initialize to nullptr
    bool *p_boolean {nullptr}; // can only store addresses of type bool
    int *p_number {nullptr}; // can only store addresses of type int
    double *p_fractional_number {nullptr}; // can only store addresses of type double

    std::cout
        << "\n"
        << "all pointers chare the same size of "
        << sizeof(p_boolean)
        << " bytes in length."
        << "\n"
        << std::endl;


    int* p_number1 {nullptr};
    int * p_number2 {nullptr};
    int *p_number3 {nullptr};

    /*
        All works the same.
        int *p_number3 format is easier to understand when you mave mutiple variables declared on the same line.
    */

    int *p_number5 {}, p_number106 {}, p_number107 {};
    int* p_number6 {}, p_number117 {}, p_number118 {};
    /*
        Confusing as you wonder if p_number117, p_number118 are also pointers.
        They are not, only p_number5 and p_number6 are pointers
        this is more clear when some are pointers and others are not
    */

    int *p_number4 {nullptr}, number95 {}, *p_number96 {nullptr};

    /*
        it can be clearer to separate these declarations on different lines.
        This leaves no room for confusion.
    */

    int *p_number7; // this is a pointer for type int
    int number8; // this is a variable of type int

    // now we know pointers store addresses of variables
    int int_var1 {43}; // a variable of type int
    int int_var2 {34}; // a variable of type int
    int *p_int{&int_var1}; // the address of variable int_var1 in memory

    std::cout
        << "int_var1 value is: "
        << int_var1
        << "\n"
        << "int_var1 pointers value is: "
        << p_int
        << "\n"
        << std::endl;

    p_int = &int_var2; // Assign a different address to the pointer but still of the same type int

    /*
        Pointers can change addresses but the new address must be the same type as the type assigned to the pointer.

        This is wrong:

            double double_var1 {3.14195};
            p_int = &double_var1

        This is correct:

            int int_var3 {3.14195};
            p_int = &int_var3
    */

    std::cout
        << "int_var2 value is: "
        << int_var2
        << "\n"
        << "int_var2 pointers value is: "
        << p_int
        << "\n"
        << std::endl;

    return 0;
}
