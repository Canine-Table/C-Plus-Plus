#include <iostream>

/*
    In some rare cases, the 'new' operator will fail to allocate dynamic memory from the heap.
    When that happens, and you have no mechanism in place to handle that failure, and exception will be thrown and your program will crash.
    VERY VERY BAD!

    'new' fails very rarely in practice and you'll see many programs that assume that it always works and don't check for memory allocation failure in any way.
    Depending on your application, failed memory allocation can be very bad and you can check and handle them so why not.
*/

int main(int argc, char **argv){
    /*
        lets try to allocate an insanely large array in one go and unhandle new failure :)
        CRASH?

        There are 2 ways of solving this problem:

            - Through the exception mechanism
            - The std::nothrow setting

        Handle the problem in a way that makes sense to your program.
        For example if you were trying to allocate memory to store color information for your application, and allocation fails, you could opt for showing some feedback message to the user, and rendering your app in black and white
    */


    // Choice number 1
    for (size_t i{}; i < -1; i++) {
        try {
            /*
                Use a huge loop to try and exhaust the memory capabilities of your system.
                When new fails, your program is going to forcefuly terminate
            */

            int *lots_of_ints1 { new int[1000000000000000000]}; // May give an error about exeeding array size

            /*
                terminate called after throwing an instance of 'std::bad_alloc'
                what():  std::bad_alloc
                Aborted (core dumped)
            */

        } catch (std::bad_alloc& e) {
            std::cout
                << "\nbad allocation error!\n"
                << "error type: "
                << e.what()
                << "\n"
                << std::endl;
            break;
        }
    }

    // Choice number 2
    for (size_t i{}; i < -1; i++) {

        int *lots_of_ints1 { new(std::nothrow) int[1000000000000000000]};

        if (lots_of_ints1 == nullptr) {

            std::cout
                << "Memory Allocation Failed!\n"
                << std::endl;

            /*
                you can also use the std::nothrow with new:
                    ex. int *lots_of_ints1 { new(std::nothrow) int[1000000000000000000]};

                    if you used this setting, dont try to dereference and use lots_of_ints1 in here.
                    you will get a UB. No memory has really been allocated here.
                    It failed and returned a nullptr because of the std::nothrow setting
            */

        } else {

            std::cout
                << "Memory Allocation succeeded!\n"
                << std::endl;

        }
    }

    return 0;
}
