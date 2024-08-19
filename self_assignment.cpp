#include<iostream>
#include <memory>
using namespace std;

class collar;

//method 1
class Dog{
    collar* pCollar;
    Dog& operator=(const Dog& rhs){
        if(this == &rhs)
            return *this;
        collar* paCollar = pCollar;
        pCollar = new collar(*rhs.pCollar);//self assignment
        delete paCollar;
        return *this;
    }
};

//method 2
/*
class Dog{
    collar* pCollar;
    dog& operator=(const dog& rhs){
        *pCollar = *rhs.pCollar; //member by member coping of collar

        return *this;
    }
}
*/

int main(){
    return 0;
}