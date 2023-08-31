#include "../../headers/common-template-utils.hpp"
#include <concepts>

/*
    Class Member variables can either be raw stack variables or pointers.
    Members can not be references.
    Classes have functions (Methods/Behaviors) that let them do things.
    Class methods have access to the member variables, regardless of whether they are public or private.
    Private members of classes (variables and functions) are not accessible from outside the class definition.
*/

class Cylinder {

    /*
        Base area:  A = pi r^2
        Volume:     V = A * h
    */

    // Class variables
    const double PI {3.14159265358979323846264338327950288};

    // Member variables
    public:
        double base_radius {1.0};
        double base_height {1.0};

    // Behaviors / Functions
    public:
        double volume(){
            return PI * base_radius * base_radius * base_height;
        }
};

int main(int argc, char **argv){

    {
        Cylinder cylinder1;
        cylinder1.base_height = 101.34;
        cylinder1.base_radius = 39.2442;
        cmtemp::display_template_one("Height: "+std::to_string(cylinder1.base_height)+"\nRadius: "+std::to_string(cylinder1.base_radius)+"\nVolume: "+std::to_string(cylinder1.volume()));
    }

    return 0;
}
