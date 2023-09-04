#include "../../../headers/common-template-utils.hpp"

#ifndef PRINTCOLL_HPP
#define PRINTCOLL_HPP

void printColl(const auto &iter); // This is still a function template

void printColl(const auto &iter){
    for (const auto &elem : iter) {
        cmtemp::display("",elem);
    }
}

#endif
