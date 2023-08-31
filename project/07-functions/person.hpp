#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class Person {

    public :
        static int person_count;

    private :
        std::string full_name {};
        int age {};

    public :
        Person(const std::string& names_param, int age_param);
        void print_info() const;
};

#endif
