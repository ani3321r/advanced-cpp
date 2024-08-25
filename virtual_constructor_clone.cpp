#include<iostream>
#include <memory>
using namespace std;

class Dog{
public:
    virtual Dog* clone(){return (new Dog(*this));} // co-variant return type
};

class YellowDog : public Dog{
    virtual YellowDog* clone() {return (new YellowDog(*this));}
};

void foo(Dog* d){ //d is yellowDog
    //Dog* c = new Dog(*d); //c is dog
    Dog* c = d->clone(); //c is yellow dog
}

int main(){
    YellowDog d;
    foo(&d);
}