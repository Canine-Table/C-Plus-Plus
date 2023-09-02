#include "../../headers/common-template-utils.hpp"
#include <string>
#include <concepts>
#include <type_traits>
#include <cctype>
#include <limits>
#include <algorithm>
#include <set>

/*
    Templates:
        Generic code for arbitrary types/values:
            - Defined with template <placeholders>
            - Types/value become clear when the generic code is used
                - The code gets compiled (instantiated) for each specific typr/value
                - Type binding still applies

        Became a very very powerful language feature:
            - More than initially expected
            - More important than inheritance (see the standard library)

        Primitive recursive language:
            - Far more than just text/code replacement
            - You can use templates to "compute" at compile time
*/

template <typename T> T max_value(T a, T b);

template <class T> T min_value(T a, T b);

/*
    Function Templates:
        Generic function code for arbitrary types

        Template definition
            - T is a common name, but anything else is possible (and maybe more readable)
            - class and typename mean the same thing
            what is funny is that it does not actually need to be a class
*/

template <typename T> void iterate(const T &iter);
void printColl(const auto &iter); // This is still a function template

/*
    Templates are usually defined in header files
        - Not only declare
        - No inline necessary

    Templates require that all operations are supported
        - Still checking still alive
*/

/*
    Implicit requirements for T:
        - operator < (returns bool)
        - copy/move constructor

    template <class T> T min_value(T a, T b){
        return b > a ? a : b;
    }

    OK: min_value(42,77);
    OK: min_value(42.0,77.0);
    OK: min_value(42.0f,77.0f);

    ERROR: min_value(42.0f,77);
        Can not deduce T (int or float)

    OK: min_value<float>(42.0f,77);

    std::complex<double> c1{3.0}, c2{4.5};
    ERROR: min_value(c1,c2);
        Deduces T as complex<>, but no < supported

    std::atomic<int> a1{3}, a2{4};
    ERROR: min_value(a1,a2);
        Deduces T as atomic<>, but copying disabled

    Often times you will not understand the error message until you understand the error.

    Concepts (since C++20)
        - To formulate formal constraints for generic code
*/
template <typename T> concept SupportsLessThan = requires(T a){
    a < a;
};

template <typename T> requires std::copyable<T> && SupportsLessThan<T> T max_value_concepts(T a, T b);

/*
    You can provide multiple template params
*/

template <typename T1, typename T2> concept SupportsLessThans = requires(T1 a, T2 b){
    a < b;
};

template <typename T1, typename T2> requires std::copyable<T1> && std::copyable<T2> && SupportsLessThans<T1,T2> auto min_value(T1 a, T2 b) -> decltype(b > a ? a : b);

int main(int argc, char **argv){

    {
        std::string max = std::to_string(max_value(4,8));
        cmtemp::display_template_one("Max Value (4 || 8): "+max);
    }

    {
        std::string min = std::to_string(min_value(4.32,8.52));
        cmtemp::display_template_two("Min Value (4.32 || 8.52): "+min);
    }

    {
        std::string min = min_value<std::string>("Hi","Ho"); // Template instanciation: <std::string>
        cmtemp::display_template_two("Min Value (Hi || Ho): "+min);
    }

    {
        char c[] {"Hello World"};
        iterate(c);
        printColl(c);

        std::vector<int> v {0,1,2,3};
        iterate(v);
        printColl(v);

        std::set<std::string> s {"Hello","World"};
        iterate(s);
        printColl(s);
    }

    {
        std::string max = std::to_string(max_value_concepts(4,8));
        cmtemp::display_template_one("Max Value (4 || 8): "+max);
    }

    {

        cmtemp::display("Min Value (4.4f || 8.4l): ",min_value(4.4f,8.4l));
    }

    return 0;
}

template <typename T> T max_value(T a, T b){
    return b < a ? a : b;
}

template <class T> T min_value(T a, T b){
    return b > a ? a : b;
}

template <typename T> void iterate(const T &iter){
    for (const auto &elem : iter) {
        cmtemp::display("",elem);
    }
}

void printColl(const auto &iter){
    for (const auto &elem : iter) {
        cmtemp::display("",elem);
    }
}

template <typename T> requires std::copyable<T> && SupportsLessThan<T> T max_value_concepts(T a, T b){
    return max_value(a,b);
}

template <typename T1, typename T2> requires std::copyable<T1> && std::copyable<T2> && SupportsLessThans<T1,T2> auto min_value(T1 a, T2 b) -> decltype(b > a ? a : b){
    return b > a ? a : b;
}

