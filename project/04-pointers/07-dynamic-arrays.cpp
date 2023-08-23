#include <iostream>

/*
    Arrays allocated on the heap with the new operator.
    Can also use the std::nothrow version of new
*/

int main(int argc, char **argv){

    const size_t SIZE {10};

    /*
        Different ways you can declare an array dynamiclly and how they are initialized
    */

    try {

        double *p_salaries {new double[SIZE]}; // sakarues array will contain garbage values

        int *p_students {new int[SIZE]{}}; // All values are initialized to 0

        double *p_scores {new(std::nothrow) double[SIZE]{1,2,3,4,5}};

        /*
            Allocating memory space for an array of size double vars.
            First 5 will be initialized with 1,2,3,4,5 and the rest with 0's
        */

        if (p_scores) { // nullptr check and use the allocated array

            for (size_t i{}; i < SIZE; ++i) {

                /*
                    Print out elements.
                    Can use regular array access notation, or pointer arithmetic
                */

                std::cout
                    << "\n"
                    << "values: "
                    << p_scores[i]
                    << " : "
                    << *(p_scores + i)
                    << std::endl;

            }
        }

        /*
            Release your dynamically allocated memory as follows [Array version].
            because we are good C++ citizens. :)
        */

        delete[] p_scores;
        p_scores = nullptr;

        delete[] p_students;
        p_students = nullptr;

        delete[] p_salaries;
        p_salaries = nullptr;

        /*
            Pointers and arrays are different

            Pointers initializedd with dynamic arrays are diffrent from arrays:
                std::size does not work on them, and they do not support range based for loops.

            double *temperatures = new double[size] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0};

                std::cout
                    << "\n"
                    << "std::size(temperatures): "
                    << std::size(temperatures)
                    << std::endl;

            The above code snippet will throw an error.
            temperatures does not have array properties that are needed for ranged based for loops to work.

                for ( double temp : temperatures) {

                    std::cout
                        << "\n"
                        << "temperature: "
                        << temp
                        << std::endl;

                }

            We say that the dynamically allocated array has decayed into a pointer which is required for using these array properties.
        */

        double *p_temperatures = {new double[SIZE] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0}};
        int *p_numbers = {new int[SIZE] {10,20,30,40,50,60,70,80,90,100}};

        for (size_t i{}; i < SIZE; i++) {

            std::cout
                << "\n"
                << "temperature: "
                << p_temperatures[i]
                << std::endl;

        }

        delete[] p_temperatures;
        p_temperatures = nullptr;

        delete[] p_numbers;
        p_numbers = nullptr;

    } catch (std::bad_alloc& e) {
        std::cout
            << "\n"
            << "error: "
            << e.what()
            << "\n"
            << std::endl;
    }

    return 0;
}
