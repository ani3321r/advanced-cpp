#include<iostream>
#include<memory>
#include<string>
using namespace std;


//  Code Reuse: Inheritance Vs. Composition
/*
class BaseDog {
   ...
   ... // common activities
};

class BullDog : public BaseDog {
   ... // Call the common activities to perform more tasks.
};

class ShepherdDog : public BaseDog {
   ... // Call the common activities to perform more tasks.
};


// Code Reuse with composition

class ActivityManager {
   ... // common activities
};

class Dog {
   ...
};

class BullDog : public Dog {
   ActivityManager* pActMngr;
   ... // Call the common activities through pActMngr
};

class ShepherdDog : public Dog {
   ActivityManager* pActMngr;
   ... // Call the common activities through pActMngr
};
*/



/*
 Code reuse: composition is better than inheritance

 1. Less code coupling between reused code and reuser of the code 
    a. Child class automatically inherits ALL parent class's public members.
    b. Child class can access parent's protected members.
       - Inheritance breaks encapsulation
*/

/*
 2. Dynamic binding
    a. Inheritance is bound at compile time
    b. Composition can be bound either at compile time or at run time.
*/

//"Friends and children, biggest enemy of your privacy. It's a philosophy of life."

class OutdoorActivityManager : public ActivityManager {...};

class IndoorActivityManager : public ActivityManager {...};


/*
 3. Flexible code construct

    Dog             ActivityManager

    BullDog         OutdoorActivityManager
    ShepherdDog     IndoorActivityManager
    ...             ...
*/