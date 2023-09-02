#include "people.hpp"

People::People(std::string_view first_name, std::string_view last_name){
    this->m_first_name = first_name;
    this->m_last_name = last_name;
}

std::ostream& operator<<(std::ostream& out, const People& People){
    out << "People: [ First name: "
        << People.m_first_name
        << ", Last name: "
        << People.m_last_name
        << ", Age: "
        << People.m_age
        << ", Gender: "
        << People.m_gender
        << " ]";
    return out;
}

std::string_view People::get_first_name(){
    return this->m_first_name;
}

std::string_view People::get_last_name(){
    return this->m_last_name;
}

char People::get_name(){
    const char *first_name {this->m_last_name.c_str()+' '};
    const char *last_name {this->m_first_name.c_str()};
    const char *full_name {*first_name+last_name};
    return *full_name;
}

People People::set_first_name(std::string_view first_name){
    this->m_first_name = first_name;
    return *this;
}
People People::set_last_name(std::string_view last_name){
    this->m_last_name = last_name;
    return *this;
}
