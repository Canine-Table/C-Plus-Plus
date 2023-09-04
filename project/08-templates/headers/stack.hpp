#include "../../../headers/common-template-utils.hpp"
#include <stack>

#ifndef STACK_HPP
#define STACK_HPP

template <typename elemT> class Stack {

    private:

        std::vector<elemT> elems; // elements

    public:
        Stack() = default; // constructor

        Stack push(const elemT &e); // push element
        Stack print() const;
        elemT pop(); // Pop top element
        elemT top() const; // Yield top element

        bool empty() const; // No elements?

};

template <typename elemT> Stack<elemT> Stack<elemT>::push(const elemT &e){
    elems.push_back(e); // insert e at the end of the stack
    return *this;
}

template <typename elemT> Stack<elemT> Stack<elemT>::print() const {
    size_t i {};
    for (const elemT &elem : elems) {
        i++;
        cmtemp::display(std::to_string(i)+") "+std::to_string(elem)+"\n");
    }
    cmtemp::display(cmtemp::add_margin(cmtemp::add_divider(),1,2));
    return *this;
}

template <typename elemT> elemT Stack<elemT>::pop(){
    assert(!elems.empty());
    elemT elem = elems.back(); // copy last element
    elems.pop_back(); // remove last element
    return elem; // return copy of removed element
}

template <typename elemT> elemT Stack<elemT>::top() const{
    assert(!elems.empty());
    return elems.back(); // return last element
}

template <typename elemT> bool Stack<elemT>::empty() const {
    return elems.empty(); // check if elems is empty
}

#endif
