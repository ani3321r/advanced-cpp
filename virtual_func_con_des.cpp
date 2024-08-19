#include<iostream>
#include <memory>
using namespace std;


class Dog{
public:
    Dog() {cout << "dog born" << endl; bark(); }// an exceptional case where dynamic binding doesn't work
    virtual void bark() {cout << "just dog" << endl;}
    void seeCat() {bark(); }
    ~Dog(){bark();}//here also the Dog will be called as brownDog will be destructed before calling it's bark
};

class brownDog : public Dog{
public:
    brownDog() {cout << "brown dog born" << endl; }
    virtual void bark() {cout << "just brown dog" << endl; }//dynamic binding
};

int main(){
    brownDog b;
    b.seeCat();
    
    return 0;
}


/*
o/p when ""void bark() {cout << "just dog" << endl;}""
dog born
brown dog born
just dog //even after calling the brownDog class, the Dog class is called
*/