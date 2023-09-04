#include "../../../headers/common-template-utils.hpp"
#include <string>
#include <concepts>
#include <type_traits>
#include <cctype>
#include <limits>
#include <algorithm>
#include <cstdint>

#ifndef PEOPLE_HPP
#define PEOPLE_HPP

template <typename G> concept Gender = requires(G gender){
    std::is_convertible<G, u_int8_t>::value;
};

template <typename A> concept Age = requires(A age){
    std::is_convertible<A, u_int32_t>::value;
};

template <typename A=u_int16_t, typename G=u_int8_t> requires Age<A> && Gender<G>
class People {

    private:
        std::string m_first_name;
        std::string m_last_name;
        u_int8_t m_gender;
        u_int16_t m_age;

    public:
        People();
        People(std::string_view first_name);
        People(std::string_view first_name, std::string_view last_name);
        People(std::string_view first_name, std::string_view last_name, A age);
        People(std::string_view first_name, std::string_view last_name, A age, G gender);

        u_int16_t get_age();
        u_int8_t get_gender();
        std::string_view get_first_name();
        std::string_view get_last_name();
        std::string_view get_name();

        People set_first_name(std::string_view first_name);
        People set_last_name(std::string_view last_name);
        People set_name(std::string_view first_name, std::string_view last_name);
        People set_gender(G gender);
        People set_age(A age);

        People get_info();
};

template <typename A, typename G>
People<A,G>::People() {
    m_first_name = "";
    m_last_name = "";
    m_age = 0;
    m_gender = '\0';
}

template <typename A, typename G>
People<A,G>::People(std::string_view first_name){
    m_first_name = first_name;
    m_last_name = "";
    m_age = 0;
    m_gender = '\0';
}

template <typename A, typename G>
People<A,G>::People(std::string_view first_name, std::string_view last_name){
    m_first_name = first_name;
    m_last_name = last_name;
    m_age = 0;
    m_gender = '\0';
}

template <typename A, typename G>
People<A,G>::People(std::string_view first_name, std::string_view last_name, A age) {
    m_first_name = first_name;
    m_last_name = last_name;
    m_age = static_cast<u_int16_t>(age);
    m_gender = '\0';
}

template <typename A, typename G>
People<A,G>::People(std::string_view first_name, std::string_view last_name, A age, G gender) {
    m_first_name = first_name;
    m_last_name = last_name;
    m_age = static_cast<u_int16_t>(age);
    m_gender = static_cast<u_int8_t>(gender);
}

template <typename A, typename G>
u_int16_t People<A,G>::get_age(){
    return m_age;
}

template <typename A, typename G>
u_int8_t People<A,G>::get_gender(){
    return m_gender;
}

template <typename A, typename G>
std::string_view People<A,G>::get_first_name(){
    return m_first_name;
}

template <typename A, typename G>
std::string_view People<A,G>::get_last_name(){
    return m_last_name;
}

template <typename A, typename G>
std::string_view People<A,G>::get_name(){
    std::string name {m_first_name + " " + m_last_name};
    return name;
}

template <typename A, typename G>
People<A,G> People<A,G>::set_first_name(std::string_view first_name){
    m_first_name = first_name;
    return *this;
}

template <typename A, typename G>
People<A,G> People<A,G>::set_last_name(std::string_view last_name){
    m_last_name = last_name;
    return *this;
}

template <typename A, typename G>
People<A,G> People<A,G>::set_name(std::string_view first_name, std::string_view last_name){
    m_first_name = first_name;
    m_last_name = last_name;
    return *this;
}

template <typename A, typename G>
People<A,G> People<A,G>::set_gender(G gender){
    m_gender = static_cast<u_int8_t>(gender);
    return *this;
}

template <typename A, typename G>
People<A,G> People<A,G>::set_age(A age){
    m_age = static_cast<u_int16_t>(age);
    return *this;
}

template <typename A, typename G>
People<A,G> People<A,G>::get_info(){
    cmtemp::display_template_one(
        "First name: "+m_first_name+
        "\nLast name: "+m_last_name+
        "\nAge: "+std::to_string(m_age)+
        "\nGender: "+std::to_string(m_gender)
    );
    return *this;
}

#endif

//class People; // Forward declaration
















//        People(std::string_view first_name);
//        People(std::string first_name, std::string_view last_name);

        // template <typename A> People(std::string_view first_name, std::string_view last_name,A auto age) requires;


//        template <typename T, typename U> People(std::string first_name, std::string last_name,T age, U gender) requires Age<T> && Gender<U>;

        // char get_name();
        // std::string_view get_first_name();
        // std::string_view get_last_name();

        // template <Gender T> T get_gender();
        // template <Age T> T get_age();

        // People set_first_name(std::string_view first_name);
        // People set_last_name(std::string_view last_name);
        // People get_info();

        // template <Gender T> People set_gender(T gender);
        // template <Age T> People set_age(T age);



// People::People(std::string_view first_name, std::string_view last_name,Age auto age){
//     m_first_name = first_name;
//     m_last_name = last_name;
//     m_gender = '\0';
//     m_age = static_cast<unsigned short>(age);
// }


// template <Gender T> People People::set_gender(T gender){
//     this->m_gender = std::toupper(gender);
//     return *this;
// }

// template <Age T> People People::set_age(T age){
//     this->m_age = age;
//     return *this;
// }

// template <Gender T> T People::get_gender(){
//     return this->m_age;
// }

// template <Age T> T People::get_age(){
//     return this->m_gender;
// }

// template <typename T, typename U> People::People(std::string first_name, std::string last_name,T age, U gender) requires Age<T> && Gender<U>{
//     // static_assert(age <= 135,"Please enter your real age.");
//     // static_assert(age >= 18,"You must be 18 years or older to participate.");

//     this->m_first_name = first_name;
//     this->m_last_name = last_name;
//     this->m_gender = std::toupper(gender);
//     this->m_age = age;
// }

// People People::get_info(){
//     cmtemp::display_template_one(
//         "\nName: "+std::to_string(get_name()));
//     return *this;
// }
