#include <string>
#include <vector>
#include <iostream>

#ifndef COMMON_TEMPLATE_UTILS_HPP
#define COMMON_TEMPLATE_UTILS_HPP

    namespace cmtemp {

        std::string add_divider (size_t count=75, char symbol='-');
        std::string add_margin (std::string output_string, size_t top_margin=1, size_t bottom_margin=1, char control_character='\n');
        void display (std::string value);
        std::string character_counter (std::string value="");
        std::string vector_to_string (std::vector<std::string> value,char divider = {32});
        void display_template_one (std::string value_one);
        void display_template_two (std::string value_one);

        template <typename T> void display (std::string value_one, T value_two) {
            std::string get_type {};
            switch (sizeof(T)) {
                case 1:
                    get_type = (typeid(T) == typeid(char)) ? "char" : "bool";
                    break;
                case 2:
                    get_type = "short";
                    break;
                case 4:
                    get_type = (typeid(T) == typeid(int)) ? "int" : "float";
                    break;
                case 8:
                    get_type = (typeid(T) == typeid(double)) ? "double" : "pointer";
                    break;
                case 16:
                    get_type = "long double";
                    break;
                case 32:
                    get_type = "string";
                    break;
                default:
                    get_type = "other";
            }

            std::cout
                << "\n"
                << value_one
                << add_margin(add_divider())
                << "\n Type: "
                << get_type
                << "\n Size: "
                << sizeof(value_two)
                << "\n Memory Location: "
                << &value_two
                << "\n Value: "
                << value_two
                << add_margin(add_divider(),2,1)
                << std::flush;
            return;
        }

        template <typename T> std::string addition (T &x,const T y) {
            return std::to_string(x - y) + " + " + std::to_string(y) + " = " + std::to_string(x += y);
        }

        template <typename T> std::string subtraction (T &x,const T y) {
            return std::to_string(x + y) + " - " + std::to_string(y) + " = " + std::to_string(x -= y);
        }

        template <typename T> std::string division (T &x,const T y) {
            return std::to_string(x * y) + " / " + std::to_string(y) + " = " + std::to_string(x /= y);
        }

        template <typename T> std::string multiplication (T &x,const T y) {
            return std::to_string(x / y) + " * " + std::to_string(y) + " = " + std::to_string(x *= y);
        }

    }

#endif
