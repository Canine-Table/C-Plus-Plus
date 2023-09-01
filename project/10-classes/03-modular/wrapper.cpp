#include "../../../headers/common-template-utils.hpp"
#include "wrapper.hpp"

Wrapper Wrapper::do_something(){
    cmtemp::display_template_one("Object Size: "+std::to_string(sizeof(*this)));
    return *this;
}

Wrapper Wrapper::print_info(){
    cmtemp::display_template_one("Name: "+m_name+"\nValue 1: "+std::to_string(m_va1)+"\nValue 2: "+std::to_string(m_va2));
    return *this;
}

int Wrapper::get_m_va1(){
    return m_va1;
}

int Wrapper::get_m_va2(){
    return m_va2;
}

std::string_view Wrapper::get_m_name(){
    return m_name;
}

Wrapper Wrapper::set_m_va1(int m_va1){
    this->m_va1 = m_va1;
    return *this;
}

Wrapper Wrapper::set_m_va2(int m_va2){
    this->m_va2 = m_va2;
    return *this;
}

Wrapper Wrapper::set_m_name(std::string_view m_name){
    this->m_name = m_name;
    return *this;
}
