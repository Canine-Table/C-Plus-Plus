#include <string>
#include <iostream>

namespace cmout {
    void greet_world (std::string name){
        std::cout
            << "\n"
            << "Hello "
            << name
            << " I hope you are doing well. :)"
            << std::endl;
        return;
    }
}
