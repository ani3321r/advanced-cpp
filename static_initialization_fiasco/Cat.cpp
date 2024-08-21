#include "Cat.h"
#include "Dog.h"
#include "Singleton.h"
#include <iostream>

extern Dog d;

void Cat::meow(){
    std::cout << "cat name " << _name << std::endl;
}

Cat::Cat(char* name){
    std::cout << "cat construction " << name << std::endl;
    _name = name;
    Singleton::getDog()->bark();
}