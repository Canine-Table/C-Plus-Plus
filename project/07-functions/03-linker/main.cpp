#include <iostream>
#include <string>
#include "compare.hpp"
#include "../../../headers/common-output-utils.hpp"

/*
    These are called:
        Include Directive
    or:
        Include Preprocessor Directive
*/

int main(int argc, char **argv){

    {
        int min_ {min(4398,349)};
        std::cout
            << min_
            << std::endl;
    }

    {
        cmout::output(cmout::add_margin(cmout::add_divider())+cmout::add_margin("Hello C family, Header files are huge time savers for sure!")+cmout::add_margin(cmout::add_divider()));
    }

    {
        std::vector<std::string> new_string {"apple", "banana", "cat", "dog", "elephant", "fox", "giraffe", "hat", "ice", "joke", "kite", "lion", "mouse", "nose", "orange", "panda", "queen", "rainbow", "star", "tree", "umbrella", "violin", "watermelon", "x-ray", "yarn", "zebra"};
        cmout::output(cmout::vector_to_string(new_string));
    }

    return 0;
}
