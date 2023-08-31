#include "../../headers/common-template-utils.hpp"
#include <concepts>

/*
    The requires clause can take four kinds of requirements:
        - simple requirements
        - nested requirements
        - compound requirements
        - type requirements
*/


template <typename T> concept TinyType = requires(T a){
    sizeof(T) <= 2; // Simple requirement: Only checks syntax
    requires sizeof(T) <= 4; // Nested requirements: checks if the condition is true
};

template <typename T> concept Addable = requires(T a, T b){
    {a+b} noexcept -> std::convertible_to<int>; /* Compound requirement
        you can strings but strings are not converable to int therefore this willl not work with non itegral or floating point types.
        Checks if a + b is valid syntax, does not throw exceptions(optional), and result is convertible to int(optional)
    */
};

TinyType auto subtract(TinyType auto a, TinyType auto b) -> decltype(a - b);
template <Addable T> T add(T a, T b);

int main(int argc, char **argv){

    {
        int int_one {10};
        int int_two {2};
        cmtemp::display_template_one(std::to_string(int_one)+" - "+std::to_string(int_two)+ " = "+std::to_string(subtract(int_one,int_two)));
    }

    {
        int int_one {10};
        int int_two {2};
        cmtemp::display_template_two(std::to_string(int_one)+" - "+std::to_string(int_two)+ " = "+std::to_string(add(int_one,int_two)));
    }

    return 0;
}

TinyType auto subtract(TinyType auto a, TinyType auto b) -> decltype(a - b){
    return a - b;
}

template <Addable T> T add(T a, T b){
    return a + b;
}
