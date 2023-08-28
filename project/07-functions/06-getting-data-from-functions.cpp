#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

/*
    Function Processing

    Input and Output function parameters

        Output parameters should be passed in such a way that you can modify the arguments from inside the function.
        Options are passing by reference or by pointer.
        References are perfered in C++.

        Input paramaters should not be modifiable from inside a function.
        The function really need to get input (read) from the arguments
        You enforce modification restrictions with the const keyword.
        Options are passed by const reference, passing by pointer to const or even passing by const pointer to const
*/

void max_str(const std::string input1, const std::string input2, std::string &output);
void max_int(const int input1, const int input2, int &output);
void max_double(const double input1, const double input2, double* output);

int main(int argc, char **argv){

    {
        std::string str_value {};
        std::string str_one ("Alabama");
        std::string str_two ("Bellevue");
        std::string str_three ("Cassablanca");

        max_str(str_one,str_two,str_value);

        cmout::output(
            cmout::add_margin(cmout::add_divider())+
            cmout::add_margin("max_str: "+str_value)+
            cmout::add_margin(cmout::add_divider())
        );

        max_str(str_three,str_two,str_value);

        cmout::output(
            cmout::add_margin("max_str: "+str_value)+
            cmout::add_margin(cmout::add_divider())
        );

    }

    {
        int int_value {};
        int int_one {45};
        int int_two {93};
        int int_three {33};

        max_int(int_three,int_one,int_value);

        cmout::output(
            cmout::add_margin("max_int: "+std::to_string(int_value))+
            cmout::add_margin(cmout::add_divider())
        );

        max_int(int_three,int_two,int_value);

        cmout::output(
            cmout::add_margin("max_int: "+std::to_string(int_value))+
            cmout::add_margin(cmout::add_divider())
        );
    }

    {
        double double_value {};
        double double_one {3.14195};
        double double_two {23.14195};
        double double_three {0.14195};

        max_double(double_one,double_three,&double_value);

        cmout::output(
            cmout::add_margin("max_int: "+std::to_string(double_value))+
            cmout::add_margin(cmout::add_divider())
        );

        max_double(double_one,double_two,&double_value);

        cmout::output(
            cmout::add_margin("max_int: "+std::to_string(double_value))+
            cmout::add_margin(cmout::add_divider())
        );

    }

    return 0;
}

void max_str(const std::string input1, const std::string input2, std::string &output){
    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}

void max_int(int input1,int input2, int &output){
    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}

void max_double(const double input1, const double input2, double* output){
    if (input1 > input2) {
        *output = input1;
    } else {
        *output = input2;
    }
}
