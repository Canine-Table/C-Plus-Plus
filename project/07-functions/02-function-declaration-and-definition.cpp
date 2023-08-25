#include "__output-utils.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

std::string add_margin (std::string output_string, size_t top_margin, size_t bottom_margin, char control_character);
std::string vector_to_string (std::vector<std::string> value,char divider);
std::string add_divider (size_t count, char symbol);
std::string character_counter (std::string value);
void output (std::string value);

int main(int argc, char **argv){

    {
        output(add_margin(add_divider())+add_margin("Hello C family, Header files are huge time savers for sure!")+add_margin(add_divider()));
    }

    {
        std::vector<std::string> new_string {"apple", "banana", "cat", "dog", "elephant", "fox", "giraffe", "hat", "ice", "joke", "kite", "lion", "mouse", "nose", "orange", "panda", "queen", "rainbow", "star", "tree", "umbrella", "violin", "watermelon", "x-ray", "yarn", "zebra"};
        output(vector_to_string(new_string));
    }

    return 0;
}
