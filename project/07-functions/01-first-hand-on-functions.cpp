#include <iostream>
#include <string>

/*
    Functions:
        A reusable piece of code that can take a number of optional inputs and produce some desirable output.

    Function Signature:
        return_type function_name (type param1, type param2, ... ...){
            ...
            return return_type;
        }

    if return_type is void the return is omited.
*/

void message (std::string message){
    std::cout
        << "\n"
        << message
        << std::endl;
    return;
}

/*
    void function that takes a single param.
    void functions do not give back the result explicitly.
*/

void enter_bar (size_t age) {
    std::string answer = (age > 18) ? "Your " + std::to_string(age) +  " years old, you may proceed." : "You are too young for this, no offense!";
    message(answer);
    return;
}

/*
    int function that takes 2 int params.
    this int function returns the greater of the 2 params.
    functions that are not void must have a return statement, this also includes type auto.
*/

int max (int a, int b) {
    return (a > b) ? a : b;
}

// This function takes no arguments and return a value of type int.
int lucky_number () {
    return 99;
}

/*
    Parameters passed this way are scoped localy in the function.
    Changes to them are not visible outside the function.
    What we have inside the function are actually COPIES of the arguments passed to the function.
*/

std::string return_value (double a, double b) {
    return {"increment: \na: " + std::to_string(a) + "\nb: " + std::to_string(b) };
}

double increment_multiply (double a, double b) {


    std::string before_increment = return_value(a,b);
    message("Inside the function, before "+before_increment);
    double result ((++a) * (++b));

    std::string after_increment = return_value(a,b);
    message("Inside the function, after "+after_increment);
    return result;
}

int main(int argc, char **argv){

    {
        for (size_t i{1}; i < 24; i++) {
            enter_bar(i);
        }
    }

    {
        message("higher nuymber, 43 or 16: " + std::to_string(max(43,16)));
        message("higher nuymber, 4 or 6: " + std::to_string(max(4,6)));
    }

    {
        message("lucky number: " + std::to_string(lucky_number()));
    }

    {
        increment_multiply(3.15,4.24);
        message("result: " + std::to_string(increment_multiply(323.15,5434.24)));
    }

    return 0;
}
