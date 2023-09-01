#include "../../../headers/common-template-utils.hpp"
#include <string>
#include <concepts>

#ifndef PEOPLE_CPP
#define PEOPLE_CPP

class People {

    std::string m_first_name {"None"};
    std::string m_last_name {"None"};
    char m_gender {'N'};
    int m_age {};

    friend std::ostream& operator<<(std::ostream& out, const People& People);

    public:

        People() = default;
        ~People() = default;

        People(std::string_view first_name, std::string_view last_name);
        People(std::string_view first_name, std::string_view last_name, int age);
        People(std::string_view first_name, std::string_view last_name, int age, char gender);

        std::string_view get_first_name();
        std::string_view get_last_name();
        std::string_view get_name();
        char get_gender();
        int get_age();

        People set_first_name(std::string_view first_name);
        People set_last_name(std::string_view last_name);
        People set_gender(char gender);
        People set_age(int age);
        People get_info();
};
#endif
