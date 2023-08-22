#include <iostream>
#include <iomanip>

long double addition(long double x, long double y){
    return x + y;
}

long double subtraction(long double x, long double y){
    return x - y;
}

long double multiplication(long double x, long double y){
    return x * y;
}

long double division(long double x, long double y){
    return x / y;
}

long modulus(long x, long y){
    return x % y;
}

int main(int argc, char **argv){

    std::cout
        << std::setprecision(20) // #include <iomanip>
        << addition(3.14195L,3.14195L)
        << "\n"
        << addition(334.14195L,13543.1234195L)
        << "\n"
        << multiplication(334.14195L,13543.1234195L)
        << "\n"
        << division(334.14195L,13543.1234195L)
        << "\n"
        << modulus(135431234195L,33414195L)
        << std::endl;

    return 0;
}
