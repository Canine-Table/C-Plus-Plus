#include <concepts>
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

#ifndef ADVANCED_TEMPLATE_UTILS_HPP
#define ADVANCED_TEMPLATE_UTILS_HPP

template <typename T1, typename T2> concept Number = requires(T1 n1, T2 n2){
    std::integral<T1> || std::floating_point<T1>;
    std::integral<T2> || std::floating_point<T2>;
};
template <typename T1, typename T2> concept Addable = requires(T1 n1, T2 n2){
    n1+n2;
    n1++;
    ++n1;
    n1+=n2;
};
template <typename T1, typename T2> concept Subtractable = requires(T1 n1, T2 n2){
    n1-n2;
    n1--;
    --n1;
    n1-=n2;
};
template <typename T1, typename T2> concept Multipliable = requires(T1 n1, T2 n2){
    n1*n2;
    n1*=n2;
};
template <typename T1, typename T2> concept Divisible = requires(T1 n1, T2 n2){
    n1/n2;
    n1/=n2;
};

class Numbers {

    private:
        double total {};
        std::vector<std::string> history {};

        void log(std::string entry){
            history.push_back(entry);
        };

        bool empty() {
            return history.empty();
        }

    public:

        Numbers() = default;

        template <typename T, typename... Tn> Numbers add(T num, Tn... nums) requires Number<T,Tn...> {

            log(std::to_string(total - num) + " + " + std::to_string(num)+" = "std::to_string(total += num)).get_last_log();
            if constexpr(sizeof...(nums) > 0) {
                add(nums...);
            } else {
                return *this;
            }
        };

        Numbers get_log(){
            assert(!history.empty());
            return *this;
        };
};

#endif
