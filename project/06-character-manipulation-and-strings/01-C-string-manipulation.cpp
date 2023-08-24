#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>


int main(int argc, char **argv){
    char message[] {"Home. The feeling of belonging."};

    // Array decays into a pointer when we use const char*
    const char *p_message[] {message};

    for (size_t i{}; i < std::size(message); i++) {

    std::cout
        << message[i];
    }

    /*
        std::strlen finds the length of a string.

            std::strlen()    excludes null characters and works wit pointers
            std::sizeof()    includes null characters and does not work pointers

        std::strlen() still works worth decayed arrays
    */

    std::cout
        << "\n\n\n"
        << *p_message
        << "\nThe message has "
        << std::strlen(*p_message)
        << " is stored at "
        << p_message
        << " in memory. \nIt has a length of "
        << std::strlen(*p_message) // <cstring>
        << " characters."
        << std::endl;

    /*
        std::strcmp - signature int strcmp( const *lhs, const char *rhs );
        Returns a negative value if lhs appears before rhs in lexicographical order.
        Zero if lhs and rhs compare equal.
        Positive if lhs appears after rhs in lexicographical order.

        lhs:    left hand string
        rhs:    right hand string

        Lexicographical order is a way of sorting or arranging words in a list or a sequence.
        It is also called alphabetical order, because it uses the order of the letters in the alphabet.
        For example, if you have a list of words like apple, banana, cherry, and date,
        you can arrange them in lexicographical order by starting with the word that begins with the letter A, then the word that begins with the letter B, and so on.
        The lexicographical order of these words is apple, banana, cherry, and date.
        Sometimes, you may have words that start with the same letter, but have different letters after that.
        In that case, you have to compare the second letters of the words, and use the alphabetical order again.
        For example, if you have a list of words like cat, car, can, and cap, you can arrange them in lexicographical order by looking at the second letters of the words.
        The lexicographical order of these words is can, cap, car, and cat. Lexicographical order is useful for finding words in a dictionary or a book index.
        It is also used in computer science and mathematics for sorting data and solving problems.
    */

    // Remember you can not change where an array points
    char char1[] {"Blabama"};
    char char2[] {"Alabama"};

    // y
    const char *p_char1 {char1};
    const char *p_char2 {char2};

    // Print out the comparison
    std::cout
        << std::strcmp(p_char1,p_char2)
        << std::endl;

    const char *p_char3 {"Alabama"};
    const char *p_char4 {"Alabamb"};

    // Print out the comparison
    std::cout
        << std::strcmp(p_char3,p_char4)
        << std::endl;


    // Print out the comparison
    std::cout
        << std::strcmp(p_char2,p_char3)
        << std::endl;

    /*
        std::strncmp:

            int strncmp(const char *lhs, const char rhs, std::size_t count)

            Compares n characters in the string.
            < 0:    Negative value if lhs appears before rhs in lexicographical order.
            0:      Returns Negative value if lhs and rhs compare are equal, or if count is zero
            > 0:    Positive value if lhs appears after rhs in lexicographical order.
    */

    const char *p_char5 {"aaaia"};
    const char *p_char6 {"aaance"};


    size_t n {3};
    std::cout
        << "aaa | aaa: "
        << std::strncmp(p_char5,p_char6,n++)
        << std::endl;

    std::cout
        << "aaace | aaaia: "
        << std::strncmp(p_char5,p_char6,n)
        << std::endl;

    /*
        std::strchr:

            Find the first occurence of a character.
            We use std::strchr to find all the matching target characters one by one.
    */


    const char *p_char7 {"jdjisjmjikjwjwqj"};
    char target {'j'};
    const char *result = p_char7;
    int iter {};
    while ((result = std::strchr(result,target)) != nullptr) {
        std::cout
            << result++
            << "<- a j was found at char number: "
            << ++iter
            << std::endl;
    }

    /*
        Find the last occurence of a target character
    */

    const char *p_char9 {"jdjisjmjikwwq"};
    const char *l_result = p_char9;
    std::cout
        << "char number: "
        << std::strrchr(l_result,target)
        << std::endl;


    char input [] {"/project/06-character-manipulation-and-strings/01-C-string-manipulation.cpp"};
    char *output {std::strrchr(input,'/')};

    if (output) {
        std::cout
            << ++output
            << std::endl;
    }
    /*
        +1 because we want to start printing past the character found by std::strrchr
    */

    return 0;
}

