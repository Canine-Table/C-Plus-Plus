#include "../../headers/common-template-utils.hpp"

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

        double get_radius(){
            return base_radius;
        }

        void set_radius(double radius_param){
            base_radius = radius_param;
        }

        double get_height(){
            return base_height;
        }

        void set_height(double height_param){
            base_height = height_param;
        }

        double volume(){
            return PI * get_radius() * get_radius() * get_height();
        }

        void get_cylinder_info() {
            cmtemp::display_template_one("Height: "+std::to_string(get_height())+"\nRadius: "+std::to_string(get_radius())+"\nVolume: "+std::to_string(volume()));
        }
};


int main(int argc, char **argv){

    {
        Cylinder cylinder1 {};
        cylinder1.set_height(923.389);
        cylinder1.set_radius(48.383343);

        Cylinder cylinder2 {101.34,39.2442};

        cylinder1.get_cylinder_info();
        cylinder2.get_cylinder_info();

    }

    return 0;
}
