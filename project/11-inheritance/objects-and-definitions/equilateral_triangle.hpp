#include "../../../headers/common-template-utils.hpp"
#include <cmath>

#ifndef EQUILATERAL_TRIANGLE_HPP
#define EQUILATERAL_TRIANGLE_HPP

class EquilateralTriangle {

    private:
        float m_length;
        float m_area;
        float m_circumference;

        void set_length(float);
        void set_circumference(float);
        void set_area(float);

    public:
        EquilateralTriangle setA(float);

        friend struct Homework;
};

EquilateralTriangle EquilateralTriangle::setA(float a){
    set_length(a);
    return *this;
}

void EquilateralTriangle::set_length(float a){
    m_length = a;
    set_circumference(m_length);
}

void EquilateralTriangle::set_circumference(float length){
    m_circumference = length * 3;
    set_area(m_circumference);
}

void EquilateralTriangle::set_area(float circumference){
    m_area = (std::sqrt(3) * std::pow(circumference,2)) / 4;
}

#endif

#ifndef HOMEWORK_HPP
#define HOMEWORK_HPP

struct Homework {
    void get_et_info(EquilateralTriangle);
};

void Homework::get_et_info(EquilateralTriangle et){
    cmtemp::display_template_one(
        "Length: "+std::to_string(et.m_length)+
        "\nCircumference: "+std::to_string(et.m_circumference)+
        "\nArea: "+std::to_string(et.m_area)
    );
}

#endif
