#include <string>
#include <vector>

#ifndef COMMON_OUTPUT_UTILS_HPP
#define COMMON_OUTPUT_UTILS_HPP

    namespace cmout {
        void greet_world (std::string name);
        std::string add_divider (size_t count=75, char symbol='-');
        std::string add_margin (std::string output_string, size_t top_margin=1, size_t bottom_margin=1, char control_character='\n');
        void output (std::string value);
        std::string character_counter (std::string value="");
        std::string vector_to_string (std::vector<std::string> value,char divider = {32});
    }

#endif
