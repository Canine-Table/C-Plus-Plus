#include <iostream>
#include <string>
#include <iomanip>

/*
    std::endl;              adds a newline character and does std::flush                            <iostream>
    std::flush;             flushes the output buffer                                               <iostream>
    std::setw;              sets the width                                                          <iomanip>
    std::left;              left justify
    std::right;             right justify
    std::internal;          center justify
    std::setfill;           set fill character                                                      <iomanip>

    std::setprecision();    sets the numbers of value after the decimal for floats and doubles      <iomanip>

    std::noboolalpha        set bool output from true/false to 1/0                                  <ios>
    std::boolalpha          set bool output from 1/0 to true/false                                  <ios>

    std::showpos            show the + sign for positive numbers for std::dec                       <ios>
    std::noshowpos          disable std::showpos and hide the + for positive numbers                <ios>

    std::hex                shows numeric data in hex format                                        <ios>
    std::oct                show numeric data in oct format                                         <ios>
    std::dec                show numeric data in dec format (default)                               <ios>
    std::showbase           appends 0x for hex and 0 for oct nothing for dec                        <ios>
    std::uppercase          turn letters to uppercase                                               <ios>
    std::nouppercase        unsets std::uppercase (default)                                         <ios>

    std::fixed              sets floating point and double values to regular notation (default)     <ios>
    std::scientific         sets floating point and double values to scientific notation            <ios>

    std::showpoint          shows the decimal point for floating point and double values            <ios>

    std::cout.unsetf(std::ios::scientific | std::ios::fixed);   reset the value to default
*/


int main(int argc, char **argv){

    // declare and initialize a 2D array of strings with the table data
    std::string table[10][3] = {
        {"John", "Doe", "45"},
        {"Alice", "Smith", "32"},
        {"Bob", "Lee", "28"},
        {"Emma", "Wang", "35"},
        {"David", "Jones", "40"},
        {"Anna", "Brown", "25"},
        {"James", "Wilson", "37"},
        {"Lisa", "Chen", "30"},
        {"Tom", "Davis", "42"},
        {"Eva", "Garcia", "29"}
    };

    // use std::cout and << operator to print the table header
    std::cout
        << std::left // left justified
        << std::setfill('=') // sets the fill character (default is space)
        << std::setw(25)
        << "first_name"
        << std::setw(25)
        << "last_name"
        << std::setw(25)
        << "age"
        << std::endl;

    // use a nested loop to print the table data
    for (int i = 0; i < 10; i++) { // loop through the rows
        for (int j = 0; j < 3; j++) { // loop through the columns

            std::cout
                << std::setfill('_') // sets the fill character (default is space)
                << std::left // left justified
                << std::setw(25)
                << table[i][j];// print the data with a fixed width
        }

        std::cout
            << std::endl;
    }

    std::cout
        << "\n--------------------------------------------\n\n"
        << std::hex
        << std::uppercase
        << std::showbase
        << "(hex) "
        << 40348346443
        << "\n"
        << "(hex) "
        << -43834928
        << "\n"
        << std::endl;

    std::cout
        << std::oct
        << std::showbase
        << "(oct) "
        << 40348346443
        << "\n"
        << "(oct) "
        << -43834928
        << "\n"
        << std::endl;

    std::cout
        << std::dec
        << std::showpos
        << std::setprecision(20)
        << std::ios::scientific
        << " (dec) "
        << 40348346443
        << "\n"
        << "(dec) "
        << -43834928
        << "\n"
        << "(dec) "
        << 389348214.348723
        << std::endl;

    return 0;
}
