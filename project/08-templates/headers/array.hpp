#include "../../../headers/common-template-utils.hpp"
#include <array>

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T, size_t SZ> struct Array {
    T elems[SZ];
    size_t size() const;
    T &operator[] (size_t idx);
    const T &operator[] (size_t idx) const;
    typedef T *iterator;
    T *begin();
    T *end();
};

template <typename T, size_t SZ> size_t Array<T,SZ>::size() const {
    return SZ;
}

template <typename T, size_t SZ> T &Array<T,SZ>::operator[] (size_t idx){
    return elems[idx];
}

template <typename T, size_t SZ> const T &Array<T,SZ>::operator[] (size_t idx) const{
    return elems[idx];
}

template <typename T, size_t SZ> T *Array<T,SZ>::begin(){
    return &elems[0];
}

template <typename T, size_t SZ> T *Array<T,SZ>::end(){
    return &elems[0] + SZ;
}

#endif
