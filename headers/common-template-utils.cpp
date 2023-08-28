#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

namespace cmtemp {


    std::string add_divider (size_t count=75, char symbol='-') {
        std::string spliter (count, symbol);
        return spliter;
    }


    std::string add_margin (std::string output_string, size_t top_margin=1, size_t bottom_margin=1, char control_character='\n') {
        control_character = iscntrl(control_character) ? control_character : '\n';
        return add_divider(
            top_margin,control_character) + output_string + add_divider(bottom_margin,control_character);
    }


    void display (std::string value) {
        std::cout
            << value
            << std::flush;
        return;
    }

    void display_template_one (std::string value_one) {
        display(
            add_margin(add_divider())+
            add_margin(value_one)+
            add_margin(add_divider(),1,2)
        );
    }

    void display_template_two (std::string value_one) {
        display(
            add_margin(value_one,0)+
            add_margin(add_divider(),1,2)
        );
    }

    std::string character_counter (std::string value="") {

        if (value == ""){
            std::cin >> value;
        } else {
            std::string value {value};
        }

        size_t total {};
            size_t printable {};
                size_t space {};
                    size_t blank {};
                size_t graphable {};
                    size_t alpha_numeric {};
                        size_t hexdecimal {};
                            size_t digit {};
                        size_t alphabetic {};
                            size_t uppercase {};
                            size_t lowercase {};
                        size_t punctuation {};
            size_t control_character {};

            const char *p_word {value.c_str()};
            while (*p_word) {
                const char& c = *p_word;
                if (std::isprint(c)){ // Checks whether c is a printable character.
                    printable++;
                    if (std::isspace(c)) { // Checks whether c is a white-space character.
                        space++;
                        if (std::isblank(c)) { // Checks whether c is a blank character.
                            blank++;
                        } // blank endblock
                    } // space endblock
                    if (std::isgraph(c)){ // Checks whether c is a character with graphical representation.
                        graphable++;
                        if (std::isalnum(c)) { // Checks whether c is either a decimal digit or an uppercase or lowercase letter.
                            alpha_numeric++;
                            if (std::isxdigit(c)){ // Checks whether c is a hexdecimal digit character.
                                hexdecimal++;
                                if (std::isdigit(c)) { // Checks whether c is a decimal digit character.
                                    digit++;
                                } // decimal
                            } // hexdecimal
                            if (std::isalpha(c)) { // Checks whether c is an alphabetic letter.
                                alphabetic++;
                                if (std::isupper(c)) { // Checks if parameter c is an uppercase alphabetic letter.
                                    uppercase++;
                                } /* upper endblock */ else { // Checks whether c is a lowercase letter.
                                    lowercase++;
                                } // lower
                            } // alpha endblock
                        } /* alnum endblock */ else if (std::ispunct(c)) { // Checks whether c is a punctuation character.
                                punctuation++;
                        } // punct endblock
                    } // graph endblock
                } /* print endblock */ else if(std::iscntrl(c)) { // Checks whether c is a control character.
                    control_character++;
                } // cntrl endblock
                total++;
                ++p_word;
            }

            return (
            add_margin(add_divider(100))+
            add_margin("Printable Characters: "+std::to_string(printable))+
            add_margin("\tSpace Characters: "+std::to_string(space))+
            add_margin("\t\tBlank Characters: "+std::to_string(blank))+
            add_margin("\tGraphable Characters: "+std::to_string(graphable))+
            add_margin("\t\tAlpha Numeric Characters: "+std::to_string(alpha_numeric))+
            add_margin("\t\t\tHexdecimal Characters: "+std::to_string(hexdecimal))+
            add_margin("\t\t\t\tDigit Characters: "+std::to_string(digit))+
            add_margin("\t\t\tAlphabetic Characters: "+std::to_string(alphabetic))+
            add_margin("\t\t\t\tUppercase Characters: "+std::to_string(uppercase))+
            add_margin("\t\t\t\tLowercase Characters: "+std::to_string(lowercase))+
            add_margin("\t\t\tPunctuation Characters: "+std::to_string(punctuation))+
            add_margin("Control Characters: "+std::to_string(control_character))+
            add_margin(add_divider(100))+
            add_margin("Total Characters: "+std::to_string(total))+
            add_margin(add_divider(100))
        );
    }

    std::string vector_to_string (std::vector<std::string> value,char divider = {32}) {
        if (!std::isprint(divider)){
            divider = {44};
        }

        std::string convert_to_string {};
        bool first = true;

        for (size_t i{}; i < size(value); i++) {
            std::string div (1,divider);
            if (first){
                first = false;
                div = (1,'\0');
            }

            convert_to_string += div + value[i];
        }

        return (convert_to_string);
    }

} // namespace cmtplte
