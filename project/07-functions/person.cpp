#include "person.hpp"
#include <iostream>
#include <iomanip>

int Person::person_count = 8;
Person::Person(const std::string& names_param, int age_param)
    : full_name(names_param), age(age_param){
        ++person_count;
};

void Person::print_info() const {
    std::cout
        << "name: "
        << full_name
        << "\n"
        << "age: "
        << age
        << std::endl;
}
