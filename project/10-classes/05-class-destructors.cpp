#include "../../headers/common-template-utils.hpp"
#include "./03-modular/dog.hpp"

/*
    Destructors

    Special methods that are called when an object dies.
    They are needed when the object needs to release some dynamic memory, or for some other kind of clean up.

    When are destructors called:

        The destructors are called in weird places that may not be obvious:
            - When an object is passed by value to a function
            - When a local object is returned from a function (for some compilers). This is subject to compiler optimization.

        Other obvious cases are:
            - When a local stack object goes out of scope (dies)
            - When a heap object is released with delete
*/

void dog_one();
void dog_obj();
void dog_obj(std::string_view name_param, std::string_view breed_param, int age_param);


int main(int argc, char **argv){

    dog_obj();
    dog_obj("Larry","Shepherd",14);

    {
        dog_one();

        Dog dog2("Greg","Affenpinscher",1);
        dog2.get_info();
    }

    Dog dog3("Fluffy","Affenpinscher",8);
    dog3.get_info();

    return 0;
}

void dog_one(){
    Dog dog1;
    dog1.set_age(5);
    dog1.set_name("Toby");
    dog1.set_breed("Shepherd");
    dog1.get_info();
}


void dog_obj(){
    Dog *obj = {new Dog()};
    obj->get_info();
    delete obj;
    obj = nullptr;
};


void dog_obj(std::string_view name_param, std::string_view breed_param, int age_param){
    Dog obj {name_param,breed_param,age_param};
    obj.get_info();
}
