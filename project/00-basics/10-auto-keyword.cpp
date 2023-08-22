#include <iostream>

/*
    Auto type deduction
    auto lets the compiler deduce the type
*/

int main(int argc, char **argv){

    auto var1 {12}; // int
    auto var2 {3.14f}; // float
    auto var3 {3.141}; // double
    auto var4 {3.14195l}; // long double
    auto var5 {'s'}; // char

    // int modifier suffixes
    auto var6 {123u}; // unsigned
    auto var7 {12ul}; // unsigned long
    auto var8 {12ll}; // long long

    std::cout
        << "var1 occupies: " << sizeof(var1) << " bytes" << "\n"
        << "var2 occupies: " << sizeof(var2) << " bytes" << "\n"
        << "var3 occupies: " << sizeof(var3) << " bytes" << "\n"
        << "var4 occupies: " << sizeof(var4) << " bytes" << "\n"
        << "var5 occupies: " << sizeof(var5) << " bytes" << "\n"
        << "var6 occupies: " << sizeof(var6) << " bytes" << "\n"
        << "var7 occupies: " << sizeof(var7) << " bytes" << "\n"
        << "var8 occupies: " << sizeof(var8) << " bytes" << "\n"
        << std::endl;

    return 0;
}
