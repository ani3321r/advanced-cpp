#include<iostream>
using namespace std;
//it is a compile time constraint due to which an object cannot be modified

int main(){
    const int i = 6; //i=6;

    const int *p1 = &i; //data is const, pointer is not
    p1++; //as pointer is not const, it can be modified

    int j=9;
    int* const p2 = &j; //pointer is const, data is not

    const int* const p3 = &j; //data and pointer both are const

    int const *p4 = &i;
    //if const is on the left of '*', data is const
    //if const is on the right of '*', pointer is const

    const int k = 9;
    const_cast<int&>(k) = 6;//cast the const value of k into a new const value

    int m;
    static_cast<const int&>(m); //changing the int m to a const value

}

//advantages of const

//guards againt inadvertent write to the variable
//self documenting
//more optimizations, making code tighter
//it can put variables into ROM