#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

/*
    Can't overload on the return type
    This is not valid:

        int max(int a, int b);
        double max(int a, int b);

    This is valid:

        int max(int a, int b);
        double max(double a, double b);

    Overloading works by chanaging the parameters  as follows
        - Order
        - Number
        - Types
*/

int max_value(int a, int b);
double max_value(double a, double b);
double max_value(int a, double b);
double max_value(double a, int b);
std::string_view max_value(std::string_view a, std::string_view b);

int main(int argc, char **argv){

    {
        max_value(3.13,244.482);
    }

    {
        max_value(3,244);
    }

    {
        max_value(3,244.14195);
    }

    {
        max_value(3.14195,244);
    }

    {
        max_value("Hello","World");
    }

    return 0;
}

int max_value(int a, int b){
    int value {(a>b) ? a : b};
    cmout::output("\n(int,int) overload\n",value);
    return value;
}

double max_value(double a, double b){
    double value {(a>b) ? a : b};
    cmout::output("\n(double,double) overload\n",value);
    return value;
}

double max_value(int a, double b){
    double value {(a>b) ? a : b};
    cmout::output("\n(int,double) overload\n",value);
    return value;

}

double max_value(double a, int b){
    double value {(a>b) ? a : b};
    cmout::output("\n(double,int) overload\n",value);
    return value;
}

std::string_view max_value(std::string_view a, std::string_view b){
    std::string_view value {(a>b) ? a : b};
    cmout::output("\n(string_view,string_view) overload\n",value);
    return value;
}
