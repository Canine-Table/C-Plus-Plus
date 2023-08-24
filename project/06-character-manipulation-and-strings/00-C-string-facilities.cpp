#include <iostream>
#include <iomanip>
#include <cctype>

/*
    C-String Facilities:
        - Length
        - Concatenate
        - Copy
        - Search

    Basic(Better) facilities to handle text data in your c++ programs

    - Check if a character is alphanumeric
    - Check if a character is alphabetic
    - Check if a character is blank
    - Check if a character is lowercase or upprtvsdr
    - Check if a character is a digit
    - Convert characters from uppercase to lowercase and vise versa using funcions like:
        - std::lower()
        - std::upper()
*/


int main(int argc, char **argv){
    char char_array[] {"Home. The feeling of belonging."};

    size_t digits {};
    size_t alnum {};
    size_t letters {};
    size_t uppers {};
    size_t lowers {};
    size_t blanks {};
    size_t other {};
    size_t totals {};

    for (size_t i{}; i < std::size(char_array); i++){

        char& ca {char_array[i]};
        if (std::isdigit(ca)) {

            digits++;

        } else if (std::isblank(ca)) {

            blanks++;

        } else if (std::isalpha(ca)) {

            letters++;

            if (std::isupper(ca)) {

                uppers++;

            } else {

                lowers++;
            }

        } else {

            other++;

        }

        totals++;
    }

    std::cout
        << std::left
        << "\n\n\n"

        << std::setw(25)
        << "Character Total: "
        << totals
        << "\n"

        << std::setw(25)
        << "Digit: "
        << digits
        << "\n"

        << std::setw(25)
        << "Letters: "
        << letters
        << "\n"

        << std::setw(25)
        << "Uppercase Letters: "
        << uppers
        << "\n"

        << std::setw(25)
        << "Lowercase Letters: "
        << lowers
        << "\n"

        << std::setw(25)
        << "Blanks: "
        << blanks
        << "\n"

        << std::setw(25)
        << "Others: "
        << other
        << "\n"

        << std::endl;

    return 0;
}



