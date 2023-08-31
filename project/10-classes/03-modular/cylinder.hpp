#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "constants.hpp"

class Cylinder {

    private:
        double base_radius {1.0};
        double base_height {1.0};

    public:
        Cylinder() = default;
        Cylinder(double radius_param, double height_param);
        double get_radius();
        void set_radius(double radius_param);
        double get_height();
        void set_height(double height_param);
        double volume();
        void get_cylinder_info();
};

#endif
