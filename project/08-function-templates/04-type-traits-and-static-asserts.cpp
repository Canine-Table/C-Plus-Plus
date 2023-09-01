#include "../../headers/common-template-utils.hpp"

/*
    Type traits can be useful for writing generic code that can work with different types of arguments or parameters.
    For example, you can use type traits to check whether a type satisfies some requirements or constraints at compile time, and use different implementations or optimizations based on the result.

        Unary:
            Unary type traits describe a property of a type, such as whether it is an integral type, a pointer type, a signed type, etc.
            They usually have a static member value that is either true or false, depending on the type.
            For example, std::is_integral<T>::value is true if T is an integral type, and false otherwise.

        Binary:
            Binary type traits describe a relationship between types, such as whether they are the same type, convertible to each other, assignable to each other, etc.
            They also have a static member value that is either true or false, depending on the types.
            For example, std::is_same<T,U>::value is true if T and U are the same type, and false otherwise1.

        Transformation:
            Transformation traits modify a property of a type, such as removing its const qualifier, adding a pointer to it, making it unsigned, etc.
            They have a static member type that is the transformed type.
            For example, std::remove_const<T>::type is the type T without its const qualifier


    Static asserts are statements that perform compile-time assertion checking.
    They take a boolean constant expression and an optional message as arguments.
    If the expression is false, the compilation fails and the message is displayed as an error.
    If the expression is true, the statement has no effect.

*/


template <typename T> T max(T x, T y);


int main(int argc, char **argv){

    {
        cmtemp::display_template_two("Max: "+std::to_string(max(3,5)));
    }

    return 0;
}

// A function template that returns the maximum of two values
template <typename T> T max(T x, T y) {
    // Use a static assert to check that T is not a pointer type
    static_assert(!std::is_pointer<T>::value,"max() does not accept pointer types");
    return x > y ? x : y;
}
