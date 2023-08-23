#include <iostream>
#include <iomanip>

int main(int argc, char **argv){

    // Non const reference
    int age {20};
    int& ref_age {age};

    std::cout
        << std::left
        << "\n"
        << std::setw(10)
        << "age"
        << std::setw(10)
        << age
        << std::setw(10)
        << &age
        << "\n"
        << std::setw(10)
        << "ref_age"
        << std::setw(10)
        << ref_age
        << std::setw(10)
        << &ref_age
        << "\n"
        << std::endl;

    /*
        Can modify original variable through reference
    */

    ref_age++; // Modify through reference;

    std::cout
        << std::left
        << "\n"
        << std::setw(10)
        << "age"
        << std::setw(10)
        << age
        << std::setw(10)
        << &age
        << "\n"
        << std::setw(10)
        << "ref_age"
        << std::setw(10)
        << ref_age
        << std::setw(10)
        << &ref_age
        << "\n"
        << std::endl;

    const int& const_age_ref{ref_age}; // Cant modify through const_age_ref

    /*
        Can achieve the same thing as const ref with a pointer: const pointer to const data.
        Remember that referebce by default is just a const pointer,
        All we need to do is make the const pointer point to const data
    */

    const int* const const_ptr_to_const_age(&age);

    /*
        *const_ptr_to_const_age = 32; Error

        Please note there is no such thing as:
            const int& const weird_ref_age{^age};

        This will give you a compiler error.

        Const applies to reference variable name.
        Not to original variable
    */

    std::cout
        << std::left
        << "\n"
        << std::setw(30)
        << "age"
        << std::setw(30)
        << age
        << std::setw(30)
        << &age
        << "\n"
        << std::setw(30)
        << "ref_age"
        << std::setw(30)
        << ref_age
        << std::setw(30)
        << &ref_age
        << "\n"
        << std::setw(30)
        << "const_age_ref"
        << std::setw(30)
        << const_age_ref
        << std::setw(30)
        << &const_age_ref
        << "\n"
        << std::setw(30)
        << "const_ptr_to_const_age"
        << std::setw(30)
        << *const_ptr_to_const_age
        << std::setw(30)
        << const_ptr_to_const_age
        << "\n"
        << std::endl;

    return 0;
}
