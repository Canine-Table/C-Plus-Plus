#include <iostream>

/*
    typename variable_name {initializer_name};

    int:
    a numeric value without a decimal
    ex 3

    float:
    a numeric value with a decimal
    ex. 3.14195

    double:
    a numeric value with a decimal which can hold larger values than float
    ex. 3.14195

    char:
    characters in memory

    bool:
    true/false

    void:
    typeless

    auto:
    not a type, but used to deduce the type to use
    ...
*/


/*
    variables:
        A named piece of data in memory that you use to store specific data types.

    Initializations:

        Braced:
            ex. int var{5}

        Functional:
            ex. int var(5)

        Assignment:
            ex. int var = 5
*/


/*
    int a {4};
    int b {4};
    Runtime Error
    int c = 10 / (a-b);
*/

int main(int argc, char **argv){

    int garbage; // var will contain a random garbage value in memory if no int is specified.
    int count {}; // Initializes to zero like garbage
    int functional_count(3.14195); // functional variable initialization. '.14195' will be lost. Implicit conversion to int silently. Less safe than braced initialization.
    int narrowing = 3.14195; // this is narrowing conversion assignment.
    int decimal {15};
    int octal {017};
    int hexadecimal {0x0f};
    int binary {0b00001111}; // Since C++14
    int total {functional_count + binary + decimal + octal + hexadecimal}; // you can use expressions as initializer

    std::cout << "Garbage: " << garbage << " is " << sizeof(garbage) << " bytes in size." << std::endl;
    std::cout << "Count: " << count << " is " << sizeof(count) << " bytes in size." << std::endl;
    std::cout << "Functional Count: " << narrowing << " is " << sizeof(narrowing) << " bytes in size." << std::endl;
    std::cout << "Narrowing Conversion: " << functional_count << " is " << sizeof(functional_count) << " bytes in size." << std::endl;
    std::cout << "Binary: " << binary << " is " << sizeof(binary) << " bytes in size." << std::endl;
    std::cout << "Octal: " << octal << " is " << sizeof(octal) << " bytes in size." << std::endl;
    std::cout << "Decimal: " << decimal << " is " << sizeof(decimal) << " bytes in size." << std::endl;
    std::cout << "Hexadecimal: " << hexadecimal << " is " << sizeof(hexadecimal) << " bytes in size." << std::endl;
    std::cout << "Total: " << total << " is " << sizeof(total) << " bytes in size." << std::endl;

    return 0;
}
