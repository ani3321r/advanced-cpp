#include<iostream>
#include <memory>
using namespace std;

// in this case only the car class is called
/*
class car{
public:    
    ~car() {cout << "car destroyed" << endl; }
};

class blueCar : public car{
    public:
        ~blueCar() {cout << "blue car destroyed" << endl; }
};

class carFactory{
    public:
        static car* createBlueCar() {return (new blueCar());}
};

int main(){
    car* pd = carFactory::createBlueCar();

    delete pd;
    return 0;
}
*/

// for the base cases
/*
class car{
public:    
    virtual ~car() {cout << "car destroyed" << endl; }
};

class blueCar : public car{
    public:
        ~blueCar() {cout << "blue car destroyed" << endl; }
};

class carFactory{
    public:
        static car* createBlueCar() {return (new blueCar());}
};

int main(){
    car* pd = carFactory::createBlueCar();

    delete pd;
    return 0;
}
*/

// using shared pointers, using unique pointers it won't be possible
// as only the car will be invoked
class car{
public:    
    ~car() {cout << "car destroyed" << endl; }
};

class blueCar : public car{
    public:
        ~blueCar() {cout << "blue car destroyed" << endl; }
};

class carFactory{
    public:
        static shared_ptr<car> createBlueCar() {
            return shared_ptr<blueCar>(new blueCar());
        }
};

int main(){
    shared_ptr<car> pd = carFactory::createBlueCar();

    return 0;
}

//all classes in stl have no virtual destructor