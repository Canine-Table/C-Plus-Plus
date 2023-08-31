#include "cylinder.hpp"

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
