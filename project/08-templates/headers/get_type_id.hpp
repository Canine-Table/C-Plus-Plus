#include "../../../headers/common-template-utils.hpp"

#ifndef GET_TYPEID_HPP
#define GET_TYPEID_HPP

template <typename T,typename... Types> void get_type_id(T firstArg, Types... args);

template <typename T,typename... Types> void get_type_id(T firstArg, Types... args){
    std::string tn = typeid(T).name();
    cmtemp::display_template_one(tn);
    if constexpr(sizeof...(args) > 0) { // compile time if
        get_type_id(args...);
    }
}

#endif
