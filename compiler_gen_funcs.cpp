#include<iostream>
#include<vector>
using namespace std;


//this are the things a compiler generated function would do
/*
class car{
    public:
        car(const car& rhs) {...}; //member be member initialization

        car& operator=(const car& rhs) {...}; //member be member coping

        car() {...}; // 1.call base class's default constructor
                     // 2. call data member's default constructor.

        ~car() {...}; // 1. call base class's destructor
                      // 2. call data member's destructor
}; 
*/


/*
copy constructor - no
copy assignment operator - yes
destructor - no
default constructor - no
*/

class bat{
    bat() = default; //way to initialize a default constructor
};

class car{
    public:
        string c_name;
        //string& c_name; //this will not work
        car(string name="honda") {c_name = name; cout << name << " is made " << endl;}
        ~car() {cout << c_name << " is destroyed " << endl; }
};

int main(){
    car c1("nissan");
    car c2;
    c2 = c1;
}

// o/p
/*
nissan is made 
honda is made 
nissan is destroyed 
nissan is destroyed 
*/