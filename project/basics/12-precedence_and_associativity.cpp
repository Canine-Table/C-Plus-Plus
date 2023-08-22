#include <iostream>
#include <iomanip>

/*
    Precedence and Associativity

    Precedence: which operation to do first
    Associativity:  which direction or which order

    It is better to make the intent in your code as clear as possible by clearly using () to indecate which operation you want done first.
*/

int main(int argc, char **argv){

    int a {6};
    int b {3};
    int c {8};
    int d {9};
    int e {3};
    int f {2};
    int g {5};

    std::cout
        << std::setprecision(20) // #include <iomanip>
        << "result: "
        << a + b * c - d / e - f + g
        << "\n"
        << "result: "
        << a / b * ((c + d - e + f) % g) * a
        << std::endl;

    return 0;
}
