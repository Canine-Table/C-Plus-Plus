#include "../../../headers/common-template-utils.hpp"
#include "point.hpp"


Point Point::set_x(double x){
    this->x = x;
    return *this;
}

Point Point::set_y(double y){
    this->y = y;
    return *this;
}

Point Point::get_coords(){
    cmtemp::display("\nPoint [ x :"+std::to_string(x)+", y : "+std::to_string(y)+" ]");
    return *this;
}
