#include "../../headers/common-template-utils.hpp"
#include "./03-modular/dog.hpp"

/*
    Each class member object contains a hidden pointer called this.
    That pointer contains the address of the current object, for which the method is being executed.
    This also applies to contrustors and destructors
*/

int main(int argc, char **argv){

    {
        Dog dog1;
        dog1.set_name("Max").set_breed("Labrador").set_age(5)->get_info();
        dog1.set_age(12)->set_name("Bella").set_breed("Poodle").get_info();
        dog1.set_name("Max").set_age(5)->set_breed("Labrador").get_info()->set_age(12)->set_name("Bella").set_breed("Poodle").get_info();
    }

    {
        Dog dog2 {2};
        dog2.set_name("Max").set_breed("Labrador").set_age(5)->get_info();
    }
    return 0;
}
