#include <string>

#ifndef DOG_CPP
#define DOG_CPP

class Dog {

    private:
        std::string *name {nullptr};
        std::string *breed {nullptr};
        int *age {nullptr};

    public:
        Dog();
        ~Dog();

        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        Dog(std::string_view name_param, std::string_view breed_param);
        Dog(int age);

        Dog* get_info();
        Dog* get_pointer();

        std::string get_name();
        std::string get_breed();
        int get_age();


        Dog* set_age(int age_param);

        Dog& set_name(std::string_view name_param);
        Dog& set_breed(std::string_view breed_param);
};

#endif
