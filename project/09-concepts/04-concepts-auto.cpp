#include "../../headers/common-template-utils.hpp"
#include <concepts>

// This Constrains the auto parameters you pass in
std::integral auto add(std::integral auto a, std::integral auto b) -> decltype(a + b);

int main(int argc, char **argv){

    {
        // Constrain declared auto var
        std::integral auto integral = 34; // must be an integral type: char, long, int, ...
        std::floating_point auto floating = 3.14195; // must be a floating point: double, float, ...
        // I find this kind of useless but if you find a use case for this than go for it, it is supported in C++.

    }

    return 0;
}

std::integral auto add(std::integral auto a, std::integral auto b) -> decltype(a + b){
    return a + b;
}
