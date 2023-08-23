#include <iostream>

/*
    When we loose access to memory that was dynamicly allocated :(
*/

int main(int argc, char **argv) {

    const int *const P_CONST_ONE {new int {10}}; // direct list initialization
    const int *const P_CONST_TWO = new int(10); // functional variable initialization

    /*
        This means that p is a constant pointer to a constant int.
        This means that you cannot change the value of either p or *p after initialization.
        For example, if you write:
            const int *const p = new int(10);

        You are creating a new int object with the value 10 and assigning its address to p.
        After this, you cannot write:
            p = new int(20);

        result error:
            cannot assign to a const pointer

        or:
            *p = 30;

        result error:
            cannot modify a const object
    */

    int *const P_CONST_THREE = new int(10);

    /*
        You are creating a new int object with the value 10 and assigning its address to p.
        After this, you can write:
            *p = 30;

        ok:
            modifying the object pointed by p

        but you cannot write:
            p = new int(20);

        result error:
            cannot assign to a const pointer

    */

    const int *P_CONST_FOUR = new int(10);

    /*
        This means that p is a pointer to a constant int. This means that you can change the value of p, but not the value of *p after initialization.
        For example, if you write:
            const int *p = new int(10);

        You are creating a new int object with the value 10 and assigning its address to p.
        After this, you can write:
            p = new int(20);

        ok:
            assigning a new address to p

        but you cannot write:
            *p = 30;

        result error:
            cannot modify a const object

    */
    // copy initialization

    delete P_CONST_ONE;
    delete P_CONST_TWO;
    delete P_CONST_THREE;
    delete P_CONST_FOUR;

    /*
        Reassignment of stack address to activate dynamic address pointer
    */

    int *p_num1 {new int {69}}; // Points to some address, say address1

    // Should delete and reset here
    delete p_num1;

    int num2 {96}; // lives at address2

    int *p_num1 = &num2;

    /*
        Now p_num2 points to address2, but address1 is still in use by our program.
        But our program has lost access to that memory location.
        This is called a memory leak
    */

    return 0;
}
