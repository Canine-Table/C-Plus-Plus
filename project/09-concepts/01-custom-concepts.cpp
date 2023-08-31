#include "../../headers/common-template-utils.hpp"
#include <concepts>

/*
    Different ways of building concepts
*/

// Syntax 1
template <typename T> concept MyIntegral = std::is_integral_v<T>;


// Syntax 2
template <typename T> concept Mutipliable = requires(T a, T b){
    a * b;
};

template <typename T> concept Incrementable = requires(T a){
    a+=1;
    a-=1;
    ++a;
    ++a;
    a++;
    a--;
};

template <typename T> concept Divisible = requires(T a, T b){
    a / b;
};

// Syntax 1
template <typename T> T add (T a, T b) requires Incrementable<T>;

// Syntax 2
template <Incrementable T> T subtract (T a, T b);

// Syntax 3
template <typename T> requires Mutipliable<T> T multiply (T a, T b);

// Syntax 4
Divisible auto divide (Divisible auto a, Divisible auto b) -> decltype(a / b);

int main(int argc, char **argv){

    {
        int int_one {10};
        int int_two {2};
        cmtemp::display_template_one(std::to_string(int_one)+" / "+std::to_string(int_two)+ " = "+std::to_string(divide(int_one,int_two)));
    }

    return 0;
}

template <typename T> T add (T a, T b) requires Incrementable<T>{

}
template <Incrementable T> T subtract (T a, T b){
    return a - b;
}

template <Mutipliable T> T multiply (T a, T b){
    return a * b;
}

Divisible auto divide (Divisible auto a, Divisible auto b) -> decltype(a / b){
    return a / b;
}
