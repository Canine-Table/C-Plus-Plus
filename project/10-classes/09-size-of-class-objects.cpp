#include "./03-modular/wrapper.hpp"

/*
    The size of a class object is the total sum of the size of the member variables
*/

int main(int argc, char **argv){

    {
        Wrapper wrap;
        wrap.set_m_name("Wrapper").set_m_va1(47).set_m_va2(375).print_info().do_something();
    }

    return 0;
}
