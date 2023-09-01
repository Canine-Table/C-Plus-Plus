#include "../../headers/common-template-utils.hpp"
#include "./03-modular/dog.hpp"
#include "./03-modular/cat.hpp"
#include "./03-modular/point.hpp"


/*
    class:  Members are private by default
    struct: Members are public by default
*/


int main(int argc, char **argv){

    {
        Cat cat1;
        cat1.m_name = "Johnny";
        cmtemp::display_template_one("Name: "+cat1.m_name);
    }

    {
        Point pt1;

        cmtemp::display(cmtemp::add_margin(cmtemp::add_divider()));
        pt1.set_x(3.12).set_y(43.2).get_coords();
        pt1.set_x(33.3).set_y(44.21).get_coords();

        pt1.x = 98.34;
        pt1.y = 34.89;
        pt1.get_coords();

        cmtemp::display(cmtemp::add_margin(cmtemp::add_divider(),2));
    }

    return 0;
}
