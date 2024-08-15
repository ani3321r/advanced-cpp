#include<iostream>
using namespace std;

//consts with functions
class Car{
    int age;
    string name;
public:
    Car() {age = 20; name="honda";}

    //const parameter

    //void setAge( int& a) {age = a;}//takes a value by reference and assigns the age

    //void setAge( int& a) {age = a; a++;}//incriments the value when the function is called

    void setAge( const int& a) {age = a;}//if we don't want to update the local variable after
    //calling the class(const reference parameter)

    //these two are same as calling by value is making a copy of it, not useful
    /*
    void setAge(const int a){age = a;}
    void setAge(int a){age = a;}
    */

    //const return value
    const string& getName() {return name;}

    //const function
    void printCarName() const {cout << name << " const" << endl;}
    void printCarName() {cout << getName() << " non-const" << endl;}
    //a const function can only call another const function
};

int main(){
    Car c;

    int i = 8;
    c.setAge(i);
    cout << i << endl;

    const string& n = c.getName();
    cout << n << endl;

    c.printCarName();//this will return the non-const value

    const Car c2;
    c2.printCarName();//this will return the const one as c2 is const
}