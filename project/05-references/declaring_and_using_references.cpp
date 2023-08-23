#include <iostream>

/*
    You must both declare and initialize a reference in one statement
    not valid c++:
        int& some_reference;

    valid c++:
        int& some_reference = {another_reference};
*/

int main(int argc, char **argv){

    int int_val {45};
    double double_val {69.96};

    int& int_val_ref1 {int_val}; // Assign through initialization
    int& int_val_ref2 = int_val; // Assign through assignment
    double& double_val_ref {double_val};

    /*
        std::setw;              sets the width                                                          <iomanip>
    std::left;              left justify

    */
    return 0;
}
