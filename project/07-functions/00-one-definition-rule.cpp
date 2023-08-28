#include "person.hpp"
#include <iostream>
#include <string>


/*
    Definitions can't show up more than once in the entire program, or Translation units.
        - Free stand alone variables
        - FUnctions
        - Classes
        - Class member functions
        - Class static member variables
*/

// Variable: This is both a Declaration and Definition.
double weight {};

/*
    is weight is declared again the linker will not know which declaration to choose.
    Since the compiler does not know what to choose it will throw linker error.
*/


double add(double a, double b){
    return a + b;
}

struct Point {
    double mx {};
    double my {};
};

int main(int argc, char **argv){

    {
        Point p1;

        std::cout
            << "p1.x: "
            << p1.mx
            << "\n"
            << "p1.y: "
            << p1.my
            << "\n"
            << std::endl;
    }


    {
        Person john {"John Doe",69};
        Person jane {"John Doe",96};

        john.print_info();
        jane.print_info();

        std::cout
            << std::endl;
    }

    return 0;
}
