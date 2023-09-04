#include "../../headers/common-output-utils.hpp"
#include <iostream>
#include <string>

template <typename T> T max_value(T a, T b);

int main(int argc, char **argv){

    {
        /*
            Explicit Template Arguments

            Explicitly say that we want the function max_value of type std::string.
            Version will be created if it does not already exist.
        */

        max_value<std::string>("World","World");
    }

    {
        /*
            This will implicitly convert double to type int
        */

        max_value<int>(3.14295,3.14195);
    }

    {
        /*
            This will implicitly convert int to type double allowing use of different types
        */

        max_value<double>(6,4.4);
    }

    return 0;
}

template <typename T> T max_value(T a, T b){
    T value {(a>b) ? a : b};
    cmout::output("",value);
    return value;
}
