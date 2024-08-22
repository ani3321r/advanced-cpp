#include "Dog.h"
#include "Cat.h"
#include <iostream>

void Dog::bark(){
    std::cout << "dog name " << _name << std::endl;
}

Dog::Dog(char* n) {
   std::cout << "dog construction " << std::endl;
   _name = n;
}