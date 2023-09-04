#include "../../headers/common-template-utils.hpp"
#include <string>
#include <concepts>
#include <type_traits>
#include <cctype>
#include <limits>
#include <algorithm>
#include <set>
#include <complex>
#include <assert.h>
#include <array>
#include <iostream>

#include "headers/array.hpp"
#include "headers/carray.hpp"
#include "headers/get_type_id.hpp"
#include "headers/iterate.hpp"
#include "headers/pack.hpp"
#include "headers/packs.hpp"
#include "headers/printColl.hpp"
#include "headers/stack.hpp"

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


/*
    Class Templates

    Class code for arbitrary types
*/

template <typename elemT> class Stack;

/*
    Generic Member functions are only instantiated if used

    Class Template arguments
        - have to support all operations of member templates that are USED
            - does not have to support all operations that COULD be used

    Example:
        OK: Stack<std::pair<int, double>> sp;
        OK: (since C++11):sp.push({5,7}).push({2,3}).push({3,0})
        ERROR: sp.print();\
            not defined for std::pair<>
*/


/*
    Class Template Arugment Deduction (CTAD)

    Constructors deduce templates parameters (since C++17)

template <typename ElemT, typename Allocator=allocator<T>> class Vector {

    public:

        Vector() = default;

        explicit Vector(const Allocator&);
        explicit Vector(size_t n, const Allocator& = Allocator());
        Vector(size_t n. const ElemT& value, const Allocator& = Allocator());
        template <typename Iter> Vector(Iter beg, Iter end, const Allocator& = Allocator());
        Vector(const Vector& x)
        Vector(const Vector&&) noexcept;
        Vector(const Vector&, const Allocator&);
        Vector(Vector&&, const Allocator&);
        Vector(iniializer_list<ElemT>, const Allocator& = Allocator());
};

    Tempified Aggregate
*/

template <typename T, size_t SZ> struct Array;

/*
    Supported types:
        - Types fpr constant integral values (int,long,enum,...)
        - std::nullptr_t (the type of nullptr)
        - Pointers to globally visible objects/functions/members
        - Lvalue references to objects or functions

    Not supported are:
        - String literals (directly)
        - Classes

    Since C++20 supported are:
        - Floating-point types(float, double, ...)
        - Data structures with public members
        - Lambdas
*/

struct CArray;

/*
    Templates for a variable number of template arguments
        - Typesafe varargs interface

    For functions and classes
    Named parameter packs
        - represent multiple arguments (types/objects)
        - can be passed together to somewhere else
*/

void Packs();

template <typename T, typename... Types> void Packs(T firstArg, Types... args);

/*
    Varisdic Templates
*/

template <typename T, typename... Types> void Packs(T firstArg, Types... args);

template <typename T, typename... Types> void Pack(T firstArg, Types... args);

template <typename T,typename... Types> void get_type_id(T firstArg, Types... args);

template <typename Coll, typename T> void add(Coll &coll, const T &val);

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
        cmtemp::display_template_two("\nMax Value (4 || 8): "+max);
    }

    {
        cmtemp::display("Min Value (4.4f || 8.4l)\n",min_value(4.4f,8.4l));
    }

    {
        Stack<int> intStack;
        cmtemp::display_template_two("\nStack is empty: "+std::to_string(intStack.empty()));
        intStack.push(1).push(2).push(3).push(4).push(5).push(6).push(7).print();
        cmtemp::display_template_two("Stack is empty: "+std::to_string(intStack.empty()));
        cmtemp::display_template_two(std::to_string(intStack.top()));
        intStack.pop();
        cmtemp::display_template_two("template <typename T, typename... Types> void Pack(T firstArg, Types... args);Stack is empty: "+std::to_string(intStack.empty()));
    }

    {
        Stack<std::string> strStack;
        strStack.push("Hello");
        cmtemp::display_template_two(strStack.top());
        strStack.pop();
    }

    {
        Stack<std::complex<double>> cpxStack;
        cpxStack.push(3.14195);
        cpxStack.pop();
    }

    {
        Array<int,10> a {4,6,3,1,7};
        cmtemp::display_template_two(std::to_string(a.size())+" elements");

        cmtemp::display(cmtemp::add_margin(cmtemp::add_divider()));
        for (size_t i {}; i < a.size(); i++){
            cmtemp::display(std::to_string(a[i])+", ");
        }
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));

        for (Array<int,10>::iterator p = a.begin(); p != a.end(); ++p){
            cmtemp::display(std::to_string(*p)+", ");
        }
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));

        for (auto p = a.begin(); p != a.end(); ++p){
            cmtemp::display(std::to_string(*p)+", ");
        }
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));

        for (const auto &elem : a){
            cmtemp::display(std::to_string(elem)+", ");
        }
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));
    }

    {
        struct CArray ca = {4,62,34,2,4};

        for (size_t i{}; i<10; ++i) {
            cmtemp::display(std::to_string(ca.elems[i])+", ");
        }
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));

        for (int *p = ca.elems; p < ca.elems+10;++p){
            cmtemp::display(std::to_string(*p)+", ");
        }
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));
    }

    {
        Packs(4,4.5f,43.4l,'C');
        cmtemp::display("..."+cmtemp::add_margin(cmtemp::add_divider()));
    }

    {

        char16_t c16;
        char32_t c32;
        char8_t c8;
        u_char uc;
        caddr_t cadd;
        unsigned long *p_ul;
        signed long sl;
        long long ll;
        const double cd {4.4};
        signed short int ssi;

        get_type_id(c8,c16,c32,uc,cadd,p_ul,sl,ll,cd,ssi);
    }

    return 0;
}

template <typename T> T max_value(T a, T b){
    return b < a ? a : b;
}

template <class T> T min_value(T a, T b){
    return b > a ? a : b;
}

template <typename T> requires std::copyable<T> && SupportsLessThan<T> T max_value_concepts(T a, T b){
    return max_value(a,b);
}

template <typename T1, typename T2> requires std::copyable<T1> && std::copyable<T2> && SupportsLessThans<T1,T2> auto min_value(T1 a, T2 b) -> decltype(b > a ? a : b){
    return b > a ? a : b;
}

template <typename Coll, typename T> void add(Coll &coll, const T &val){
    coll.push_back(val);
}
