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

    int a {4};
    int b {4};
    Runtime Error
    int c = 10 / (a-b);

    NOTE:
        Initializations:
            Copy:
                This is the simplest form of initialization, which uses the assignment operator = to assign a value to a variable.
                For example:
                    int x = 10;
                    std::string s = "Hello";
                This works by creating a temporary object of the same type as the variable, and then copying its value to the variable.
                This can be inefficient for some types, such as classes or arrays, that have expensive copy operations.
                Copy initialization also requires that the type of the value is compatible with the type of the variable, or that there is a conversion constructor that can convert the value to the type of the variable.
                For example, you cannot use copy initialization to initialize an array with a list of values, or to initialize a class with multiple arguments.

            Direct:
                This is a more general form of initialization, which uses parentheses () to enclose the value or values to initialize a variable.
                For example:
                    int x(10);
                    std::string s("Hello");
                This works by calling the constructor of the type of the variable with the value or values as arguments.
                This can be more efficient for some types, such as classes or arrays, that have move operations or initializer-list constructors.
                Direct initialization also allows more flexibility in the type of the value or values, as long as there is a matching constructor that can accept them.
                For example, you can use direct initialization to initialize an array with a list of values, or to initialize a class with multiple arguments.

            Uniform:
                This is a newer form of initialization, introduced in C++11, which uses braces {} to enclose the value or values to initialize a variable.
                For example:
                    int x{10};
                    std::string s{"Hello"};
                Uniform initialization works similarly to direct initialization, by calling the constructor of the type of the variable with the value or values as arguments. However, uniform initialization has some advantages over direct initialization, such as:
                    - It can prevent narrowing conversions, which are implicit conversions that may lose information or precision.
                      For example, you cannot use uniform initialization to initialize an int variable with a double value, or a char variable with an int value.
                    - It can be used for any type of variable, including arrays, classes, enums, and aggregates (structures or unions).
                      For example, you can use uniform initialization to initialize an array with a list of values, or to initialize a class with multiple arguments.
                    - It can be used for default initialization, which means giving a default value to a variable when no value is specified.
                     For example, you can use uniform initialization to initialize an int variable with zero, or a string variable with an empty string.
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
