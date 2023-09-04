#include "../../headers/common-template-utils.hpp"
#include <iostream>
#include <string>
#include <cstring>

template <typename T> T max_value(T a, T b);
template <> const char* max_value<const char*>(const char* a, const char* b);

int main(int argc, char **argv){

    {
        int int_one {48};
        int int_two {35};

        max_value(int_one,int_two);
    }

    {
        const char *char_one {"hello\0"};
        const char *char_two {"animal\0"};

        max_value(char_one,char_two);
    }

    return 0;
}

template <typename T> T max_value(T a,T b){
    T value {(a>b) ? a : b};
    cmtemp::display("",value);
    return value;
}

template <> const char* max_value<const char*>(const char* a, const char* b) {
    const char* value {(std::strcmp(a,b) > 0) ? a : b};
    cmtemp::display("",value);
    return value;
}
