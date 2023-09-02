#include "../../../headers/common-template-utils.hpp"
#include <string>
#include <concepts>
#include <type_traits>
#include <cctype>
#include <limits>
#include <algorithm>

#ifndef PEOPLE_CPP
#define PEOPLE_CPP

template <typename T> concept Gender = requires(T gender){
    std::is_integral<T>::gender &&
    std::is_unsigned<T>::gender &&
    std::numeric_limits<T>::min() == 0 &&
    std::numeric_limits<T>::max() == 255
    && std::isalpha(static_cast<char>(T {})) &&
    std::find("MmFf", "MmFf" + 4, static_cast<char>(T {})) != "MmFf" + 4;
};

template <typename T> concept Age = requires(T age){
    std::is_integral<T>::age &&
    std::is_unsigned<T>::age && sizeof(T) == 4;
};

class People {

    std::string m_first_name {};
    std::string m_last_name {};
    char m_gender {};
    unsigned int m_age {};

    friend std::ostream& operator<<(std::ostream& out, const People& People);

    public:

        People() = default;
        ~People() = default;

        People(std::string_view first_name, std::string_view last_name);
        template <Age T> People(std::string_view first_name, std::string_view last_name,T age);
        template <Age T, Gender U> People(std::string_view first_name, std::string_view last_name,T age, U gender);

        char get_name();
        std::string_view get_first_name();
        std::string_view get_last_name();

        template <Gender T> T get_gender();
        template <Age T> T get_age();

        People set_first_name(std::string_view first_name);
        People set_last_name(std::string_view last_name);
        People get_info();

        template <Gender T> People set_gender(T gender);
        template <Age T> People set_age(T age);

};

template <Gender T> People People::set_gender(T gender){
    this->m_gender = std::toupper(gender);
    return *this;
}

template <Age T> People People::set_age(T age){
    this->m_age = age;
    return *this;
}

template <Gender T> T People::get_gender(){
    return this->m_age;
}

template <Age T> T People::get_age(){
    return this->m_gender;
}

template <Age T> People::People(std::string_view first_name, std::string_view last_name, T age){
    // static_assert(age <= 135,"Please enter your real age.");
    // static_assert(age >= 18,"You must be 18 years or older to participate.");

    this->m_first_name = first_name;
    this->m_last_name = last_name;
    this->m_age = age;
}

template <Age T, Gender U> People::People(std::string_view first_name, std::string_view last_name, T age, U gender){
    // static_assert(age <= 135,"Please enter your real age.");
    // static_assert(age >= 18,"You must be 18 years or older to participate.");

    this->m_first_name = first_name;
    this->m_last_name = last_name;
    this->m_gender = std::toupper(gender);
    this->m_age = age;
}

// People People::get_info(){
//     cmtemp::display_template_one(
//         "\nName: "+std::to_string(get_name()));
//     return *this;
// }

#endif
