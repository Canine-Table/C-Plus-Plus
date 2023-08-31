#include "../../headers/common-template-utils.hpp"
#include "./03-modular/dog.hpp"

int main(int argc, char **argv){

    {
        Dog dog1 {"Fluffy", "Shepherd", 4};
        dog1.get_info();

        Dog dog2 {"Spot", "Dalmatian", 3};
        dog2.get_info();

        Dog dog3 {"Max", "Labrador", 5};
        dog3.get_info();

        Dog dog4 {"Bella", "Poodle", 2};
        dog4.get_info();

        Dog dog5 {"Luna", "Husky", 6};
        dog5.get_info();

        Dog dog6 {"Rocky", "Boxer", 1};
        dog6.get_info();

        Dog dog7 {"Coco", "Chihuahua", 7};
        dog7.get_info();
    }

    return 0;

}
