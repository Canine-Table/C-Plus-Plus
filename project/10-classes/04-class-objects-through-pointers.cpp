#include "../../headers/common-template-utils.hpp"
#include "./03-modular/cylinder.hpp"

int main(int argc, char **argv){

    {
        // Stack object
        Cylinder cylinder1 {};
        cylinder1.set_height(135.384);

        cylinder1.get_cylinder_info();

        // Managing a Stack object through pointers
        Cylinder *p_cylinder1 = &cylinder1;
        (*p_cylinder1).set_radius(835.283);

        p_cylinder1->get_cylinder_info();

        p_cylinder1 = nullptr;
    }

    {
        // Heap object
        Cylinder *cylinder2 = {new Cylinder {983.369,243.483}};

        // Syntax 1: Dereference Operator with dot notation
        (*cylinder2).get_cylinder_info();

        // Syntax 2: Pointer Access Operator
        cylinder2->get_cylinder_info();

        delete cylinder2;
        cylinder2 = nullptr;
    }

    return 0;
}
