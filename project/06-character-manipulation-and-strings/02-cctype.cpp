#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector> // include the header file for vector

/*
    vector<int> arr; // declare a vector of int
    arr.push_back(1); // push 1 to the end of the vector
    arr.push_back(2); // push 2 to the end of the vector
    arr.pop_back(); // pop the last element from the vector
    arr.insert(arr.begin(), 3); // insert 3 at the beginning of the vector
    arr.erase(arr.begin() + 1); // erase the second element from the vector

    NOTE:
        std::size() is an alias for std::length()

*/

void divider(int counter=75, std::string character="-",int mtp=0,int mbm=0) {

    std::string mt {};
    std::string mb = {};
    const std::string esc ("\n");

    if (mtp) {
        for (size_t i{}; i < mtp; i++) {
            mt += esc;
        }
    }

    std::string divide = mt;
    for (size_t i{}; i < counter; i++){
        divide += character;
    }

    if (mbm) {
        for (size_t i{}; i < mbm; i++) {
            mb += esc;
        }
    }

    std::cout
        << divide
        << mb
        << std::flush;
}

int main(int argc, char **argv){
    std::string words[] {"apple", "banana", "cat", "dog", "elephant", "fox", "giraffe", "hat", "ice", "joke", "kite", "lion", "mouse", "nose", "orange", "panda", "queen", "rainbow", "star", "tree", "umbrella", "violin", "watermelon", "x-ray", "yarn", "zebra"};
    std::vector<std::string> word_characters {};

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

    for (size_t i{}; i < std::size(words); i++) {

        std::string word {words[i]};
        reverse(word.begin(), word.end());
        const char *p_word {word.c_str()};

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

        size_t size {std::size(word_characters)};
        if (size) {
            bool avalible {true};
            const char *p_word {word.c_str()};
            int idx {};
            while (avalible) {
                int& index {idx};
                if (index == size){
                    reverse(word.begin(), word.end());
                    word_characters.push_back(word);
                    avalible = false;
                } else {
                    const char *p_index {word_characters[index].c_str()};
                    if (std::strcmp(p_word,p_index) == -1) {
                        reverse(word.begin(), word.end());
                        word_characters.insert(word_characters.begin() + index -1, word);
                        avalible = false;
                    } else {
                        index++;
                    }
                }
            }
        } else {
            reverse(word.begin(), word.end());
            word_characters.push_back(word);
        }
    }

    const size_t COLUMNS {4};
    const size_t ROWS {word_characters.size() % COLUMNS};
    divider(100,"-",3,3);
    while (word_characters.size()) {
        if ((word_characters.size() - ROWS) % 4 == 0) {
            divider(0,{},1);
        }

        std::cout
            << std::left
            << std::setw(25)
            << word_characters[0];
        word_characters.erase(word_characters.begin());
    }

    divider(100,"-",3,3);
    std::cout
        << "Printable Characters: "
        << printable
        << "\n\n"
        << "\tSpace Characters: "
        << space
        << "\n\n"
        << "\t\tBlank Characters: "
        << blank
        << "\n\n"
        << "\tGraphable Characters: "
        << graphable
        << "\n\n"
        << "\t\tAlpha Numeric Characters: "
        << alpha_numeric
        << "\n\n"
        << "\t\t\tHexdecimal Characters: "
        << hexdecimal
        << "\n\n"
        << "\t\t\t\tDigit Characters: "
        << digit
        << "\n\n"
        << "\t\t\tAlphabetic Characters: "
        << alphabetic
        << "\n\n"
        << "\t\t\t\tUppercase Characters: "
        << uppercase
        << "\n\n"
        << "\t\t\t\tLowercase Characters: "
        << lowercase
        << "\n\n"
        << "\t\t\tPunctuation Characters: "
        << punctuation
        << "\n\n"
        << "Control Characters: "
        << control_character
        << std::endl;
    divider(100,"=",3,1);
    std::cout
        << "Total Characters: "
        << total;
    divider(100,"=",1,3);
    return 0;
}
