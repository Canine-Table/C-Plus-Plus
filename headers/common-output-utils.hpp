#include <string>
#include <vector>

#ifndef COMMON_OUTPUT_UTILS_HPP
#define COMMON_OUTPUT_UTILS_HPP

    namespace cmout {
        std::string add_divider (size_t count=75, char symbol='-');
        std::string add_margin (std::string output_string, size_t top_margin=1, size_t bottom_margin=1, char control_character='\n');
        std::string character_counter (std::string value="");
        std::string vector_to_string (std::vector<std::string> value,char divider = {32});
        void output (std::string value);
        void output (std::string value_one, int value_two);
        void output (std::string value_one, double value_two);
        void output (std::string value_one, std::string value_two);
        void output (std::string value_one, bool value_two);
        void output (std::string value_one, std::string_view value_two);
        void output (std::string value_one, char value_two);
//        template <typename T> void output (std::string value_one, T value_two);
        void overloaded_output(auto value);
    }

#endif
