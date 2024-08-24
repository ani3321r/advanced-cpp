#include<iostream>
#include <string>
#include <vector>
using namespace std;

// here as the main refence is being deleted it will not work
/*
class Person{
public:
    Person(string name) { pName_ = new string(name); }
    ~Person(){delete pName_;}

    void printName(){ cout << *pName_; }

private:
    string* pName_;    
};
*/


//sol1
class Person{
public:
    Person(string name) { pName_ = new string(name); }
    ~Person(){delete pName_;}
    Person(const Person& rhs){
        pName_ = new string(*(rhs.pName()));
    }
    Person& operator=(const Person& rhs); //Deep copying
    void printName(){ cout << *pName_; }
    string* pName() const {return pName_;}

private:
    string* pName_;    
};

//sol2(this is more preferable)
/*
class Person{
public:
    Person(string name) { pName_ = new string(name); }
    ~Person(){delete pName_;}
    void printName(){ cout << *pName_; }
    string* pName() const {return pName_;}
    Person* clone(){
        return (new Person(*(pName_)));
    }
private:
    Person(const Person& rhs);
    Person& operator=(const Person& rhs); //Deep copying
    string* pName_;    
};
*/


int main(){
    vector<Person> persons;
    persons.push_back(Person("raj "));// here the person is copied and pushed into the vector(shallow copy)

    persons.back().printName();

    cout << "end" << endl;
}