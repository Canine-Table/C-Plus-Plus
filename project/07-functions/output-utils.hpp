#ifndef OUTPUT_UTILS_H

#define OUTPUT_UTILS_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

#include "output-utils.cpp"

using namespace std;

string add_divider (size_t count, char symbol);
string add_margin (string output_string, size_t top_margin, size_t bottom_margin, char control_character);
void output (string value);
string character_counter (string value);
string vector_to_string (vector<string> value,char divider);

#endif
