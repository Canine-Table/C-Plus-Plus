#include <iostream>

/*
    The break statement after each case fall through is very important.
    It stops processing the switch block if one of the call case fall throughs is a match.
    If the break statement is not there, all the cases following the matching case fall through will be executed.

    switch case statements must be Integral types and enums: int,long,char,short,unsigned,etc.
*/

int main(int argc, char **argv){

    char grade;

    std::cout
        << "What was your grade?: ";
    std::cin >> grade;

    switch (grade) {
        case 'a':
        case '4':
        case 'A': { // If grade is A, print “Excellent!”
            std::cout
                << "Excellent!"
                << std::endl;
            break; // Exit the switch statement
        } case 'b':
        case '3':
        case 'B': { // If grade is B, print “Well done”
            std::cout
                << "Well done"
                << std::endl;
                 break; // Exit the switch statement
        } case 'c':
        case '2':
        case 'C': { // If grade is C, print “Good”
            std::cout
                << "Good"
                << std::endl;
            break; // Exit the switch statement
        } case 'd':
        case '1':
        case 'D': { // If grade is D, print “You passed”
            std::cout
                << "You passed"
                << std::endl;
            break; // Exit the switch statement
        } case 'f':
        case '0':
        case 'F': {// If grade is F, print “Better try again”
            std::cout
                << "Better try again"
                << std::endl;
            break; // Exit the switch statement
        } default: { // If grade is none of the above, print “Invalid grade”
            std::cout
                << "Invalid grade"
                << std::endl;
        }
    }

    return 0;
}
