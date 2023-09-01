#include "people.hpp"


People::People(std::string_view first_name, std::string_view last_name){
    this->m_first_name = first_name;
    this->m_last_name = last_name;
}

People::People(std::string_view first_name, std::string_view last_name, int age){
    this->m_first_name = first_name;
    this->m_last_name = last_name;
    this->m_age = age;
}

People::People(std::string_view first_name, std::string_view last_name, int age, char gender){
    this->m_first_name = first_name;
    this->m_last_name = last_name;
    this->m_gender = gender;
    this->m_age = age;
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

std::string_view People::get_name(){
    return this->m_first_name +  " " +this->m_last_name;
}

char People::get_gender(){
    return static_cast<char>(this->m_gender);
}

int People::get_age(){
    return this->m_age;
}

People People::set_first_name(std::string_view first_name){
    this->m_first_name = first_name;
    return *this;
}
People People::set_last_name(std::string_view last_name){
    this->m_last_name = last_name;
    return *this;
}

People People::set_gender(char gender){
    this->m_gender = gender;
    return *this;
}

People People::set_age(int age){
    this->m_age = age;
    return *this;
}

People People::get_info(){
    cmtemp::display_template_one("\nName: "+m_first_name+" "+m_last_name+"\nAge: "+std::to_string(get_age())+"\nGender: "+get_gender());
    return *this;
}
