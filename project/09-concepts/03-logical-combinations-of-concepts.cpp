#include "../../headers/common-template-utils.hpp"
#include <concepts>

/*
    Logical combinations of concepts

    Concepts and be combined with the && and || operators.
*/

template <typename T,typename U> concept TinyType = requires(T a, U b){
    sizeof(T) == 4;
    sizeof(U) == 4;
};

template <typename T,typename U> concept Numeric = requires(T a, U b){
    requires std::integral<T> || std::floating_point<T>;
    requires std::integral<U> || std::floating_point<U>;
};

template <typename T,typename U> T Integer(T &a, U b) requires Numeric<T,U> && TinyType<T,U> && requires(T a, U b){
    requires sizeof(T) == 4;
    requires sizeof(U) == 4;
};


int main(int argc, char **argv){

    {
        float float_one {3.14195};
        float float_two {3.14195};
        int int_one {5};
        int int_two {82};

            cmtemp::display_template_one(std::to_string(float_one / float_two)+" * "+std::to_string(float_two)+ " = "+std::to_string(Integer(float_one,float_two)));
            cmtemp::display_template_two(std::to_string(float_one / int_one)+" * "+std::to_string(int_one)+ " = "+std::to_string(Integer(float_one,int_one)));
            cmtemp::display_template_two(std::to_string(float_one / int_two)+" * "+std::to_string(int_two)+ " = "+std::to_string(Integer(float_one,int_two)));

    }

    {
        int int_one {1};

        for (int i{1}; i < 9; i++){
            cmtemp::display_template_two(std::to_string(int_one / i)+" * "+std::to_string(i)+ " = "+std::to_string(Integer(int_one,i)));
        }
    }

    return 0;
}

template <typename T,typename U> T Integer(T &a, U b) requires Numeric<T,U> && TinyType<T,U> && requires(T a, U b){
    requires sizeof(T) == 4;
    requires sizeof(U) == 4;
}{
    return a *= b;
}
