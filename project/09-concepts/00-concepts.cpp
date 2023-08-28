#include "../../headers/common-template-utils.hpp"
#include <concepts>

/*
    One of the big 4 features of C++ 20

    An alternative to static asserts and type traits

    template <typename T> void print_number(T n){
        static_assert(std::is_integral<T>::value, "Must pass in an integral argument");
        std::cout
            << "n: "
            << n
            << std::endl;
    }

    A mechanism to place constraints on your template type parameters

    Types:

        Standard builtin concepts:
            - same_as                       specifies that a type is the same as another
            - derived_from                  specifies that a type is derived from another
            - convertable_to                specifies that a type is implicitly convertable to another type
            - common_reference_with         specifies that two types share a common reference type
            - common_with                   specifies that two types share a common type
            - integral                      specifies that a type is an integral type
            - signed_integral               specifies that a type is an integral type that is signed
            - unsigned_integral             specifies that a type is an integral type that is unsigned
            - floating_point                specifies that a type is a floating-point type

        Custom concepts:
            - ...
*/

// Syntax 1
template <typename T> requires std::integral<T> T add (T a, T b);

// Syntax 2
template <std::integral T> T subtract (T a, T b);

// Syntax 3
auto multiply (std::integral auto a, std::integral auto b) -> decltype(a * b);


// Syntax 4
template <typename T> T divide (T a, T b) requires std::integral<T>;


int main(int argc, char **argv){

    {
        char char_one {10};
        char char_two {20};
        cmtemp::display_template_one(std::to_string(char_one)+" + "+std::to_string(char_two)+ " = "+std::to_string(add(char_one,char_two)));
    }

    {
        int int_one {610};
        int int_two {250};
        cmtemp::display_template_two(std::to_string(int_one)+" - "+std::to_string(int_two)+ " = "+std::to_string(subtract(int_one,int_two)));
    }

    {
        int int_one {55};
        int int_two {55};
        cmtemp::display_template_two(std::to_string(int_one)+" * "+std::to_string(int_two)+ " = "+std::to_string(multiply(int_one,int_two)));
    }

    {
        int int_one {645};
        int int_two {5};
        cmtemp::display_template_two(std::to_string(int_one)+" / "+std::to_string(int_two)+ " = "+std::to_string(divide(int_one,int_two)));
    }


    return 0;
}


template <typename T> requires std::integral<T> T add (T a, T b){
    return a + b;
}

template <std::integral T> T subtract (T a, T b){
    return a - b;
}

auto multiply (std::integral auto a, std::integral auto b) -> decltype(a * b){
    return a * b;
}

template <typename T> T divide (T a, T b) requires std::integral<T>{
    return a / b;
}
