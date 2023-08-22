#include <iostream>
#include <cmath>

/*
    std::floor();
    std::ceil();
    std::abs();
    std::cos();
    std::exp();
    std::log();
    std::pow();
    std::sqrt();
    std::round();
    std::sin();
    std::tan();
*/

int main(int argc, char **argv){
    short a {45};
    int b {148};
    long c {-9834};
    float d {94.34823};
    double e {38.27387832};
    long double f {9834.934889754325};

    std::cout
        << std::scientific
        << "45 pow 148 is: "
        << std::pow(a,b)
        << "\n"

        << "9834.934889754325 log in base 10 is: "
        << std::log10(f)
        << "\n"

        << "9834.934889754325 log in base is: "
        << std::log(f)
        << "\n"

        << "the sqrt of 9834.934889754325 is: "
        << std::sqrt(f)
        << "\n"

        << "the abs value of -9834 is: "
        << std::abs(c)
        << "\n"

        << "the exp value of 2.34823 is: "
        << std::exp(2.34823)
        << "\n"

        << "9834.934889754325 floor is: "
        << std::floor(f)
        << "\n"

        << "9834.934889754325 round is: "
        << std::round(f)
        << "\n"

        << "9834.934889754325 ceil is: "
        << std::ceil(f)
        << "\n"

        << std::endl;

    return 0;
}
