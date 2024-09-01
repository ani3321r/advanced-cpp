#include<iostream>
#include<memory>
#include<string>
/*
 C++ Keyword: using 

 1. using directive: to bring all namespace members into current scope
   Example:  
      using namespace std;
*/



/* 2. using declaration
   a. Bring one specific namespace member to current scope. 
   b. Bring a member from base class to current class's scope. 
   Example:
*/
   using std::cout;
   cout << "Hello world.\n";


using namespace std;  // case 1, global scope
using std::cout;     // case 2.a, gloabal scope

class B {
   public:
   void f(int a);
};
 
class D : private B { 
   public:
      void g() { 
         using namespace std;  // case 1, local scope
         cout << "From D: \n";
      }
      void h() { 
         using std::cout;     // case 2.a, local scope
         cout << "From D: \n";
      }
      using B::f;   // case 2.b,  class scope
      using std::cout; // not allowed
      using namespace std; // not allowed
};
using B::f; // not allowed

D d;
d.f(8);


/* Notes:
 1. using declaration and using directive, when used on namespace, can 
    be used in global or local scope.
 2. using declaration can be used in class scope, when used on class members.
*/

class B {
   public:
      void f(int a);
};
 
class D : public B { 
   public:
      using B::f;
      void f();
};

int main() {
   D d;
   d.f(8);
}



// Anonymous Namespace

static void h() { std::cout << "h()\n"; }

void g() { std::cout << "global g()\n"; }
namespace {
   void g() { std::cout << "g()\n"; }
   void h() { std::cout << "h()\n"; g(); }
}

int main() {
   h();
}