#ifndef COMMON_OUTPUT_UTILS_HPP

#define COMMON_OUTPUT_UTILS_HPP
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

#include "common-output-utils.cpp"

namespace cmout {
    void greet_world (std::string name);
    // std::string add_divider (size_t count, char symbol);
    // std::string add_margin (std::string output_string, size_t top_margin, size_t bottom_margin, char control_character);
    // void output (std::string value);
    // std::string character_counter (std::string value);
    // std::string vector_to_string (std::vector<std::string> value,char divider);
}

#endif
