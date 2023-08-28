#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

std::string local_say_age(int age);
std::string p_say_age(int *age);

int main(int argc, char **argv){

    int age {20};

    {
        cmout::output(cmout::add_margin(local_say_age(age),0,2));
        cmout::output(cmout::add_margin(local_say_age(age),0,2));
    }

    cmout::output(cmout::add_margin(cmout::add_divider(),0,1));
    std::cout
        << "Address of age: "
        << &age
        << "\nHello, you are "
        << age
        << " years old."
        << std::endl;
    cmout::output(cmout::add_margin(cmout::add_divider(),0,2));

    {
        cmout::output(cmout::add_margin(p_say_age(&age),0,2));
        cmout::output(cmout::add_margin(p_say_age(&age),0,2));
        cmout::output(cmout::add_margin(p_say_age(&age),0,2));
    }

    return 0;
}

std::string local_say_age(int age){
    std::cout
        << "Address of age: "
        << &age
        << std::endl;
    return "Hello, you are "+std::to_string(++age)+" years old.";
}

std::string p_say_age(int *age){
    std::cout
        << "Address of age: "
        << age
        << std::endl;
    return "Hello, you are "+std::to_string(++(*age))+" years old.";
}
