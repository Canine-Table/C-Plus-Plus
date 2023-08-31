#include "../../../headers/common-template-utils.hpp"
#include "cylinder.hpp"

/*
    ::     Scope resolution operator
*/

Cylinder::Cylinder(double radius_param, double height_param){
    base_radius = radius_param;
    base_height = height_param;
}

double Cylinder::get_radius(){
    return base_radius;
}

void Cylinder::set_radius(double radius_param){
    base_radius = radius_param;
}

double Cylinder::get_height(){
    return base_height;
}

void Cylinder::set_height(double height_param){
    base_height = height_param;
}

double Cylinder::volume(){
    return PI * get_radius() * get_radius() * get_height();
}

void Cylinder::get_cylinder_info() {
    cmtemp::display_template_one("Height: "+std::to_string(get_height())+"\nRadius: "+std::to_string(get_radius())+"\nVolume: "+std::to_string(volume()));
}
