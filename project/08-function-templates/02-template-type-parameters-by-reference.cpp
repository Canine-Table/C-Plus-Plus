#include "../../headers/common-template-utils.hpp"
#include <iostream>
#include <string>

template <typename T> const T& max_value(const T a,const T b, T &c);

int main(int argc, char **argv){

    {
        double int_value {};

        max_value(438.348,438.38,int_value);
        max_value<double>(-3443,-3372,int_value);
        max_value<double>(2334,732,int_value);
        max_value(34.24,32.2,int_value);
    }

    {
        double value {3.14195};
        cmtemp::display_template_one(cmtemp::addition(value,53.38));
        cmtemp::display_template_two(cmtemp::addition(value,82.21));
        cmtemp::display_template_two(cmtemp::multiplication(value,952.195));
        cmtemp::display_template_two(cmtemp::subtraction(value,298.232));
        cmtemp::display_template_two(cmtemp::division(value,12.1253));
        cmtemp::display_template_two(cmtemp::addition(value,43903.38));
        cmtemp::display_template_two(cmtemp::addition(value,52343.38));
    }

    {
        int value {5};
        cmtemp::display_template_one(cmtemp::multiplication(value,2));
        cmtemp::display_template_two(cmtemp::multiplication(value,2));
        cmtemp::display_template_two(cmtemp::multiplication(value,2));
        cmtemp::display_template_two(cmtemp::division(value,2));
        cmtemp::display_template_two(cmtemp::division(value,2));
        cmtemp::display_template_two(cmtemp::division(value,2));
    }

    return 0;
}

template <typename T> const T& max_value(const T a,const T b, T &c){
    T value {(a>b) ? a : b};
    [&c](T val) -> void {
        c += val;
    }(value);
    cmtemp::display("",c);
    return c;
}

