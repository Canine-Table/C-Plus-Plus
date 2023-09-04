#include "../../../headers/common-template-utils.hpp"

#ifndef PACKS_HPP
#define PACKS_HPP

void Packs(){};

template <typename T, typename... Types> void Packs(T firstArg, Types... args);

template <typename T, typename... Types> void Packs(T firstArg, Types... args){
    cmtemp::display(std::to_string(firstArg)+", ");
    Packs(args...);
}

#endif
