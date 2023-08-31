#include "../../headers/common-template-utils.hpp"
#include <concepts>

/*
    Class Constructors

    A special kind of method that is called when an instance of a class is created:
        - No return type
        - Same name as the class
        - Can have parameters. Can also have an empty parameter list
        - Usually used to initialize members of a class
*/


class Cylinder {

    const double PI {3.14159265358979323846264338327950288};

    private:
        double base_radius {1.0};
        double base_height {1.0};

    public:
        Cylinder() = default;

        Cylinder(double radius_param, double height_param){
            base_radius = radius_param;
            base_height = height_param;
        }

        double volume(){
            return PI * base_radius * base_radius * base_height;
        }
};


int main(int argc, char **argv){

    {
        Cylinder cylinder1 {};
        Cylinder cylinder2 {101.34,39.2442};

        cmtemp::display_template_one("Volume: "+std::to_string(cylinder1.volume()));
        cmtemp::display_template_two("Volume: "+std::to_string(cylinder2.volume()));

    }

    return 0;
}
