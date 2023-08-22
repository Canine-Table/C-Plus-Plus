#include <iostream>
#include <limits>

    /*
        std::numeric_limits<T>::min()

        std::numeric_limits<T>::max()

        std::numeric_limits<T>::lowest()       this does nothing for integral types
    */

int main(int argc, char **argv){

    std::cout
        << "The range for <short> is from "
        << std::numeric_limits<short>::min()
        << " to "
        << std::numeric_limits<short>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <int> is from "
        << std::numeric_limits<int>::min()
        << " to "
        << std::numeric_limits<int>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <long> is from "
        << std::numeric_limits<long>::min()
        << " to "
        << std::numeric_limits<long>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <char> is from "
        << std::numeric_limits<char>::min()
        << " to "
        << std::numeric_limits<char>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <bool> is from "
        << std::numeric_limits<bool>::min()
        << " to "
        << std::numeric_limits<bool>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <unsigned short> is from "
        << std::numeric_limits<unsigned short>::min()
        << " to "
        << std::numeric_limits<unsigned short>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <unsigned int> is from "
        << std::numeric_limits<unsigned int>::min()
        << " to "
        << std::numeric_limits<unsigned int>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <unsigned long> is from "
        << std::numeric_limits<unsigned long>::min()
        << " to "
        << std::numeric_limits<unsigned long>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <unsigned char> is from "
        << std::numeric_limits<unsigned char>::min()
        << " to "
        << std::numeric_limits<unsigned char>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <signed short> is from "
        << std::numeric_limits<signed short>::min()
        << " to "
        << std::numeric_limits<signed short>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <signed int> is from "
        << std::numeric_limits<signed int>::min()
        << " to "
        << std::numeric_limits<signed int>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <signed long> is from "
        << std::numeric_limits<signed long>::min()
        << " to "
        << std::numeric_limits<signed long>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <signed char> is from "
        << std::numeric_limits<signed char>::min()
        << " to "
        << std::numeric_limits<signed char>::max()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <float> is from "
        << std::numeric_limits<float>::min()
        << " to "
        << std::numeric_limits<float>::max()
        << " and the lowest value is "
        << std::numeric_limits<float>::lowest()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <double> is from "
        << std::numeric_limits<double>::min()
        << " to "
        << std::numeric_limits<double>::max()
        << " and the lowest value is "
        << std::numeric_limits<double>::lowest()
        << "\n"
        << std::endl;

    std::cout
        << "The range for <long double> is from "
        << std::numeric_limits<long double>::min()
        << " to "
        << std::numeric_limits<long double>::max()
        << " and the lowest value is "
        << std::numeric_limits<long double>::lowest()
        << "\n"
        << std::endl;

    return 0;
}
