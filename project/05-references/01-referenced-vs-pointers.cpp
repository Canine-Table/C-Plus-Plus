#include <iostream>
#include <iomanip>

/*
    References:

        - Does not use dereferencing for reading and writing
        - Can't be changed to reference something else
        - Must be initialized at declaration

    Pointers:

        - Must go through dereference operator to read and weite to pointed value
        - Can be changed to point somewhere else
        - Can be declared un-initialized (will contain garbage address)

*/

int main(int argc, char **argv){

    // Declare pointer and reference

    double double_val {3.14195};

    double& ref_double_val {double_val}; // Reference to double_val
    double *p_double_val {&double_val}; // Pointer to double_val

    /*
        without dereferencing a pointer with * you will be accessing the memory address location the pointer is pointing to.
    */

    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::endl;

    // Writing through pointer
    *p_double_val = 5.91413;

    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::endl;

    // Writing through reference
    ref_double_val = 95.1413;

    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::endl;


    double_val = 3.14195;
    double other_double_var {439.0349034};

    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::endl;

    /*
        This works, but does not make ref_double_val reference other_double_var.
        This merely makes the value which ref_double_val is referencing equal to the value stored within other_double_var.

    */

    ref_double_val = other_double_var;


    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::setw(25)
        << "*other_double_var"
        << other_double_var
        << "\n"
        << std::endl;

    /*
        If you change ref_double_val now,
        other_double_val stays the same proving ref_double_bal is not referencing other double_val.
    */

    other_double_var = 44.44444;
    ref_double_val = 33.33333;

    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::setw(25)
        << "*other_double_var"
        << other_double_var
        << "\n"
        << std::endl;

    /*
        Can't make a reference refer to something else
    */

    // A pointer can point somewhere else
    p_double_val = &other_double_var;
    other_double_var = 349.328923;

    std::cout
        << std::left
        << "\n\n\n"
        << std::setw(25)
        << "double_val"
        << double_val
        << "\n"
        << std::setw(25)
        << "ref_double_val"
        << ref_double_val
        << "\n"
        << std::setw(25)
        << "*p_double_val"
        << *p_double_val
        << "\n"
        << std::setw(25)
        << "*other_double_var"
        << other_double_var
        << "\n"
        << std::endl;

    /*
        References are somewhat like const pointers
        References behave like const pointers, but they have a much friendlier syntax as they dont require dereferencing to read and write through referenced data.
    */

    return 0;
}
