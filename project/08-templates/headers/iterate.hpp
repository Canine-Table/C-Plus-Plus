#include "../../../headers/common-template-utils.hpp"

#ifndef ITERATE_HPP
#define ITERATE_HPP

template <typename T> void iterate(const T &iter);

template <typename T> void iterate(const T &iter){
    for (const auto &elem : iter) {
        cmtemp::display("",elem);
    }
}

#endif
