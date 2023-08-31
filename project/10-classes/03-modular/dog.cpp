#include "../../../headers/common-template-utils.hpp"
#include "dog.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

Dog::Dog(){
    name = { new std::string {"John Doe"}};
    breed = { new std::string {"Unknown"}};
    age = {new int {}};
    cmtemp::display_template_one(*name+" was created.");
};

Dog::~Dog(){

    cmtemp::display_template_one(*name+" was deleted.");

    delete name;
    name = nullptr;

    delete breed;
    breed = nullptr;

    delete age;
    age = nullptr;
}

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param){
    name = { new std::string {name_param}};
    breed = { new std::string {breed_param}};
    age = {new int {age_param}};
    cmtemp::display_template_one(*name+" was created.");
}

Dog::Dog(std::string_view name_param, std::string_view breed_param){
    name = { new std::string {name_param}};
    breed = { new std::string {breed_param}};
    age = {new int {}};
    cmtemp::display_template_one("name "+*name+" and breed "+*breed+" was created.");
}

Dog::Dog(int age){
    breed = { new std::string {"Unknown"}};
    name = { new std::string {"John Doe"}};
    this->age = {new int {age}};
    cmtemp::display_template_one("dog age of "+std::to_string(*this->age)+" was created.");
}

Dog* Dog::get_info(){
    std::ostringstream oss;
    oss << get_pointer();
    cmtemp::display_template_one("Name: "+get_name()+"\nBreed: "+get_breed()+"\nAge: "+std::to_string(get_age())+"\nPointer: "+oss.str());
    return get_pointer();
}

Dog* Dog::get_pointer(){
    return this;
}

std::string Dog::get_name(){
    return *name;
}

std::string Dog::get_breed(){
    return *breed;
}

int Dog::get_age(){
    return *age;
}

Dog* Dog::set_age(int age_param){
    *age = age_param;
    return get_pointer();
}

Dog& Dog::set_name(std::string_view name_param){
    *name = name_param;
    return *this;
}

Dog& Dog::set_breed(std::string_view breed_param){
    *breed = breed_param;
    return *this;
}
