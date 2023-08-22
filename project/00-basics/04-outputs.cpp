#include <iostream>
#include <string>
#include <map>

/*
    std::cout   Print data to the console(terminal)
    ex. std::cout << "enter your age: " << std::endl;

    std::cin    Reading data from the terminal
    ex. std::cin first >> second >> third;

        to store data with spaces you can use std::getline();
        ex. std::getline(std::cin,var);

    std::cerr   Printing errors to the console
    ex. std::cerr << "Printing errors to the console" << std::endl;

    std::clog   Printing log messages to the console
    ex. ex. std::clog << "Printing log messages to the console" << std::endl;
*/


int setAge(){
    int age;
    std::cout << "enter your age: ";
    std::cin >> age;
    return age;
}

std::string setName(){
    std::map<std::string, std::string> name;
    std::cout << "enter your first name: ";
    std::cin >> name["first_name"];
    std::cout << "enter your last name: ";
    std::cin >> name["last_name"];
    return name["first_name"] + " " + name["last_name"];
}

int main(){

    int age = setAge();
    std::string name = setName();
    std::cout << "Hello "
        << name
        << " who is "
        << age
        << " years old!"
        << std::endl;

    return 0;
}
