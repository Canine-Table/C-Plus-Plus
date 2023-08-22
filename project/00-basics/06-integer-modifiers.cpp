#include <iostream>

/*
    These modifiers onlu apply to integral types:
        Those in which uou can store decimal numbers
        Fractional numbers will give you a compilation error

    Signed:
        Range: [0 ~ 2^n - 1] or [-2,147,483,648 ~ 2,147,483,648]
        Bytes in Memory: 4

    Unsigned:
        Range: [-2^n-1 ~ 2^n-1 - 1] or [0 ~ 4,294,967,295]
        Bytes in Memory: 4

    Short:
        Bytes in Memory: 2

    Long:
        Bytes in Memory: 4 or 8
*/

int main(int argc, char **argv){

    signed int positives_and_negatives {-5};
    unsigned int positives_only {5};
    short int short_int {127};
    long int long_int {534934};

    std::cout
        << positives_and_negatives
        << std::endl
        << positives_only
        << std::endl
        <<short_int
        << std::endl
        <<long_int
        << std::endl;

    return 0;
}
