#include "objects-and-definitions/player.hpp"
#include "objects-and-definitions/equilateral_triangle.hpp"

#include <iostream>

/*
    A defining feature of Object Oriented Programming in C++
    Built types on top of other types
    Inheritance hierarchies can be set up to suit your needs
    Code Reuse is important

    With public inheritance, derived classes can access and use public members of the base class, but can not directly access private members
*/

int main(int argc, char **argv){

    {
        People people1;
        People people2("John");
        People people3("John","Doe");
        People people4("John","Doe",446);
        People people5("John","Doe",4,'M');

        people1.set_age(35).set_first_name("Jane").set_last_name("Doe").set_gender('M').get_info();

        people5.get_info();
    }

    {
        EquilateralTriangle et;
        et.setA(5.53);
        Homework h;
        h.get_et_info(et);
    }

    {
        Player player1("Blue","Tennis");
        Player player2("Red","Tennis");

        player1.set_age(27).set_first_name("David").set_last_name("Jones").set_gender('M').get_info();
        std::cout << player1 << std::endl;

        player2.set_age(25).set_first_name("Kevin").set_last_name("Lee").set_gender('M').get_info();

        std::cout << player2 << std::endl;

        player2.set_age(35).set_first_name("Jane").set_last_name("Doe").set_gender('M').get_info();
        player2.get_info();
    }

    return 0;
}
