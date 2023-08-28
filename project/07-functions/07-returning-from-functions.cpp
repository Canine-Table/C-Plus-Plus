#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

/*
    Returning from functions [Default is by value]
*/

int total_sum(int a, int b);

/*
    In modern compilers, return by value is commonly optimized out by the compiler when possible and the function is modified behind your back to return by reference avoiding unecessary copies.
*/

std::string add_string(std::string str_one, std::string str_two);

int main(int argc, char **argv){

    {
        int get_sum {total_sum(49,439)};

        cmout::output(
            cmout::add_margin(cmout::add_divider())+
            cmout::add_margin("49 + 439 = "+std::to_string(get_sum))+
            cmout::add_margin(cmout::add_divider(),1,2)
        );
    }

    {
        std::string str_result = add_string(std::string("Hello"),std::string("World!"));
        std::cout
            << "Out : &str_result(std::string): "
            << &str_result // Same memory address as result
            << "\nSize of result: "
            << sizeof(str_result)
            << " bytes."
            << std::endl;
        cmout::output(cmout::add_margin(cmout::add_divider()));
    }

    return 0;
}

int total_sum(int a, int b){
    return a + b;
}

std::string add_string(std::string str_one, std::string str_two){
    std::string result = str_one + str_two;

    std::cout
        << "In : &result(std::string): "
        << &result // Same memory address as str_result
        << "\nSize of result: "
        << sizeof(result)
        << " bytes."
        << std::endl;
    cmout::output(cmout::add_margin(cmout::add_divider(),1,2));
    return result;
}
