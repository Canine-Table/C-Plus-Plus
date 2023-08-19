#include <iostream>


int sum(int first_number, int second_number){
    return first_number + second_number;
}

int main(){

    int first_number {5}; // direct list initialization1
    int second_number = 5; // copy initialization

    std::cout << "5 + 5 = " << sum(5,5) << std::endl;
    std::cout << first_number << " + " << second_number << " = " << first_number + second_number << std::endl;

    return 0;
}
