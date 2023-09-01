#include "../../../headers/common-template-utils.hpp"
#include <string>
#include <concepts>
#include <type_traits>
#include <cctype>
#include <limits>
#include <algorithm>

#ifndef PEOPLE_CPP
#define PEOPLE_CPP

template <typename T> concept Gender = requires(T value){
    std::is_integral<T>::value &&
    std::is_unsigned<T>::value &&
    std::numeric_limits<T>::min() == 0 &&
    std::numeric_limits<T>::max() == 255
    && std::isalpha(static_cast<char>(T {})) &&
    std::find("MmFf", "MmFf" + 4, static_cast<char>(T {})) != "MmFf" + 4;
};

template <typename T> concept Age = requires(T value){
    std::is_integral<T>::value &&
    std::is_unsigned<T>::value && sizeof(T) == 4;
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
        People(std::string_view first_name, std::string_view last_name,Age auto age);
        People(std::string_view first_name, std::string_view last_name,Age auto age, Gender auto gender);

        std::string_view get_first_name();
        std::string_view get_last_name();
        std::string_view get_name();
        char get_gender();
        Age auto get_age();

        People set_first_name(std::string_view first_name);
        People set_last_name(std::string_view last_name);
        People set_gender(Gender auto gender);
        People set_age(Age auto age);
        People get_info();
};

#endif
