#include<iostream>
#include<memory>
#include<string>
using namespace std;

/*
Public inheritance => "is-a" relation
A Derived class should be able to do everything the base class can do.
*/

class Bird { 
   public:
   void fly();
};

class Penguin : public Bird {};

Penguin p;
p.fly();


// class flyableBird : public bird {};
//   public:
//      void fly();
//penguin p;
//p.fly();

class Dog {
   public:
      void bark() { cout << "Whoof, I am just a dog.\n";};
};

class Yellowdog : public Dog{
   public:
      void bark() { cout << "Whoof, I am a yellow dog.\n";};
};

int main() {
   Yellowdog* py = new Yellowdog();
   py->bark(); 
   Dog* pd = py;
   pd->bark(); 
}

// OUTPUT:
// Whoof, I am a yellow dog.
// Whoof, I am just a dog.

// Never Override Non-virtual Functions



/*
class Dog {
   public:
   void bark(int age) { cout << "I am " << age; }
   virtual void bark(string msg = "just a" ) { 
      cout << "Whoof, I am " << msg << " dog." << endl; }
};

class Yellowdog : public Dog {
   public:
   using Dog::bark;
   virtual void bark(string msg="a yellow" ) { 
      cout << "Whoof, I am " << msg << " dog." << endl; }
};

int main() {
   Yellowdog* py = new Yellowdog();
   py->bark(5); 
}
*/

// OUTPUT:
// Whoof, I am a yellow dog.
// Whoof, I am just a dog.

/*
 Never redefine default parameter for virtual function
   - Default parameters are bound statically;
   - Virtual functions are bound dynamically.
 */


/*
  in class dog, add:
  virtual void bark(int age) { cout << "I am " << age << " years old"<< endl; }
  int main(){
    py->bark(5);  // Won't compile
                   // Can be fixed by adding "using Dog::bark;" in yellow dog
  }
 */