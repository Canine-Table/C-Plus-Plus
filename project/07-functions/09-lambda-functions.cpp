#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

/*
    Lamda Functions:

        A mechanism to set up anonymous functions (without names).
        Once we have them set up, we can either give them names and call them, or wn evn get them to do things directly.

    Lambda function signature:
        [capture list] (paramaters) -> return type {
            function body
        };
*/

int main(int argc, char **argv){

    {
        auto greeting = [](std::string name) -> void /* return type (Optional)*/ {
            cmout::output(
                cmout::add_margin(cmout::add_divider())+
                cmout::add_margin("Hello World! This is "+name+".")+
                cmout::add_margin(cmout::add_divider())
            );
        };

        greeting("Canine Table");
        greeting("Canine Table");
        greeting("Canine Table");
    }

    {
        [](std::string name) -> void { // Calling a lambda function without a name
            cmout::output(
                cmout::add_margin(cmout::add_divider())+
                cmout::add_margin("Hello "+name+".")+
                cmout::add_margin(cmout::add_divider())
            );
        }("Canine Table");
    }

    {
        cmout::output(
            cmout::add_margin(cmout::add_divider())+
            cmout::add_margin([](std::string name) -> std::string {
                return "Hello everyone! This is " + name + ".";
            }("Canine Table"))+
            cmout::add_margin(cmout::add_divider())
        );
    }

    {
        /*
            Capture lists are use tot capture values out side the scope of the lambda function.
        */

        std::string first_name {"Canine"};

        cmout::output(
            cmout::add_margin(cmout::add_divider())+
            cmout::add_margin([first_name](std::string last_name="") -> std::string {
                return "Hello everyone! This is " + first_name  + last_name + ".";
            }(" Table"))+
            cmout::add_margin(cmout::add_divider())
        );

        cmout::output(
            cmout::add_margin(cmout::add_divider())+
            cmout::add_margin([first_name](std::string last_name="") -> std::string {
                return "Hello everyone! This is " + first_name + last_name + ".";
            }())+
            cmout::add_margin(cmout::add_divider())
        );

        int value {};

        auto addition = [&value](int add) -> std::string {
            return cmout::add_margin(std::to_string(value - add) + " + " + std::to_string(add) + " = " + std::to_string(value += add));
        };

        cmout::output(addition(43));
        cmout::output(addition(34));
        cmout::output(addition(-93));
        cmout::output(addition(389) + cmout::add_margin(cmout::add_divider()));

    }

    {

        int int_value {3};
        double double_value {3.14195};

        /*
            Capture everything by value
        */

        auto display_value = [=]() -> std::string {
            return cmout::add_margin("int_value: "+std::to_string(int_value) + "\ndouble_value: " + std::to_string(double_value));
        };

        /*
            Capture everything by reference
        */

        auto display_reference = [&]() -> std::string {
            return cmout::add_margin("int_value: "+std::to_string(int_value) + "\ndouble_value: " + std::to_string(double_value));
        };

        for (size_t i{}; i< 10; i++){
            int_value *= 2;
            double_value *= 5;

            cmout::output(display_reference()); // values will update when referenced values are changed
            cmout::output(display_value() + cmout::add_margin(cmout::add_divider())); // values will stay the same as when declared
        }

        auto display_new_value = [=]() -> std::string {
            return cmout::add_margin("int_value: "+std::to_string(int_value) + "\ndouble_value: " + std::to_string(double_value));
        };

        cmout::output(display_new_value() + cmout::add_margin(cmout::add_divider())); // values will stay the same as when first declared

    }

    return 0;
}
