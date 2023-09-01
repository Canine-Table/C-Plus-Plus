#include <string>

#ifndef WRAPPER_HPP
#define WRAPPER_HPP

class Wrapper {

    int m_va1 {};
    int m_va2 {};
    std::string m_name {};

    public:

        Wrapper do_something();
        Wrapper print_info();
        Wrapper set_m_va1(int m_va1);
        Wrapper set_m_va2(int m_va1);
        Wrapper set_m_name(std::string_view m_name);

        int get_m_va1();
        int get_m_va2();
        std::string_view get_m_name();
};

#endif
