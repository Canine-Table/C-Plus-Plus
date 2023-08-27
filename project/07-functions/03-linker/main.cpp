#include <iostream>
#include <string>
#include "compare.hpp"

/*
    These are called:
        Include Directive
    or:
        Include Preprocessor Directive
*/

int main(int argc, char **argv){
    int min_ {min(4398,349)};
    std::cout
        << min_
        << std::endl;

    return 0;
}
