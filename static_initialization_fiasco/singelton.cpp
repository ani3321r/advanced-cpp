#include "Singleton.h"
#include "Dog.h"
#include "Cat.h"

Dog* Singleton::pd = 0;
Cat* Singleton::pc = 0;

Dog* Singleton::getDog(){
    if(!pd)
        pd = new Dog("roni");
    return pd;
}

Cat* Singleton::getCat(){
    if(!pc)
        pc = new Cat("brown");;
    return pc;    
}

Singleton::~Singleton(){
    if(pd) delete pd;
    if(pc) delete pc;
    pd = 0;
    pc = 0;
}