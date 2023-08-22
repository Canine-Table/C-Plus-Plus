#include <iostream>
#include <iomanip>
#include <cmath>

/*
    Floaiting Point Types
        Scientific Notation can be used for floating point and integral types types

    Floating Point Numbers Memory Representation: IEEE_754

    n(floating point)/0 = Infinity(+/-) (inf)
    0.0/0.0 = NaN (nan)

    Float:

        Byte Size in Memory: 4
        Precision: 7
        ex. 3.1415926f

    Double:

        Byte Size in Memory: 8
        Precision: 15 (recommended default)
        ex. 3.141592653589793
    Long Double:

        Byte Size in Memory: 12
        Precision: > Double
        ex. 3.141592653589793L

*/


int main(int argc, char **argv){

    float num1 {3.1415926f};
    double num2 {3.141592653589793};
    double num3 {3.141592653589793e8};
    long double num4 {3.141592653589793L};
    long double num5 {3.14e-11L};
    float zero {0.0};

    std::cout
        << "-------------------------------------------\n\n"
        << std::setprecision(7) // included in <iomanip>
        << std::fixed
        << num1
        << "\n"
        << num2
        << "\n"
        << num3
        << "\n"
        << std::endl;

    std::cout
        << "-------------------------------------------\n\n"
        << std::setprecision(3)
        << std::scientific // included in <cmath>
        << num4
        << "\n"
        << num5
        << "\n"
        << num3 * num5
        << "\n"
        << num3 * num5 / num3 / num5
        << "\n"
        << num1 / zero
        << "\n"
        << zero / zero
        << std::endl;

    return 0;
}
