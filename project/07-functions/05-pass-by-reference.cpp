#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

std::string r_say_age(int &age);


int main(int argc, char **argv){

    int age {20};

    {
        cmout::output(cmout::add_margin(r_say_age(age),0,2));
        cmout::output(cmout::add_margin(r_say_age(age),0,2));
        cmout::output(cmout::add_margin(r_say_age(age),0,2));
    }

    return 0;
}

std::string r_say_age(int &age){
    std::cout
        << "Address of age: "
        << &age
        << std::endl;
    return "Hello, you are "+std::to_string(++(age))+" years old.";
}
