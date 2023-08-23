#include <iostream>
#include <iomanip>

/*
    You must both declare and initialize a reference in one statement
    not valid c++:
        int& some_reference;

    valid c++:
        int& some_reference = {another_reference};
*/

std::string div(int value, std::string symbol = "-"){
    std::string line {"\n" + symbol};

    for(size_t i{}; i < value; i++){
        line += symbol;
    }

    return line += "\n";
}

int main(int argc, char **argv){

    int int_val {45};
    double double_val {69.96};

    int& int_val_ref1 {int_val}; // Assign through initialization
    int& int_val_ref2 = int_val; // Assign through assignment
    double& double_val_ref {double_val};

    int_val_ref2 = 334;
    int_val_ref1 = {25 + 15 + 15 + 25 + 15};
    double_val_ref = 96.69;

    std::cout
        << div(int_val_ref2)
        << "\n"
        << std::left
        << std::boolalpha
        << std::setw(25)
        << "label"
        << std::setw(15)
        << "value"
        << std::setw(15)
        << "reference"
        << std::setw(25)
        << "address"
        << std::setw(15)
        << "bytes"
        << "\n"
        << div(int_val_ref2)
        << std::setw(25)
        << "int_val"
        << std::setw(15)
        << int_val
        << std::setw(15)
        << false
        << std::setw(25)
        << &int_val
        << std::setw(15)
        << sizeof(int_val)
        << "\n"

        << std::setw(25)
        << "int_val_ref1"
        << std::setw(15)
        << int_val_ref1
        << std::setw(15)
        << true
        << std::setw(25)
        << &int_val_ref1
        << std::setw(15)
        << sizeof(int_val_ref1)
        << "\n"

        << std::setw(25)
        << "int_val_ref2"
        << std::setw(15)
        << int_val_ref2
        << std::setw(15)
        << true
        << std::setw(25)
        << &int_val_ref2
        << std::setw(15)
        << sizeof(int_val_ref2)
        << "\n"

        << std::setw(25)
        << "double_val"
        << std::setw(15)
        << double_val
        << std::setw(15)
        << false
        << std::setw(25)
        << &double_val
        << std::setw(15)
        << sizeof(double_val)
        << "\n"

        << std::setw(25)
        << "double_val_ref"
        << std::setw(15)
        << double_val_ref
        << std::setw(15)
        << true
        << std::setw(25)
        << &double_val_ref
        << std::setw(15)
        << sizeof(double_val_ref)
        << div(int_val_ref2)
        << std::endl;

    return 0;
}
