#include<iostream>
#include<memory>
#include<string>


// Koenig Lookup

// Example 1:
namespace A
{
   struct X {};
   void g( X ) { cout << " calling A::g() \n"; }
}

void g( X ) { cout << " calling A::g() \n"; }

int main() {
   A::X x1;
   g(x1);   // Koenig Lookup, or Argument Dependent Lookup (ADL)
}

//1. Remove A:: from A::g(x);
//2. Add a global g(A::X);
// Argument Dependent Lookup (ADL)



// Example 2:
class C {
   public:
   struct Y {};
   static void h(Y) { cout << "calling C::h() \n"; }
};

int main() {
   C::Y y;
   h(y);  // Error
}

// Remove C::



// Example 3:
namespace A
{
   struct X {};
   void g( X ) { cout << " calling A::g() \n"; }
}

class B {
   void g(A::X ) { cout << "calling B::g() \n" ; }
};

class C : public B {
   public:
   void j() {
      A::X x;
      g(x);
   }
};

int main() {
   C c;
   c.j();
}

//1. Ambiguous call to g();
//2. Change C to a class, no more ambiguity.
//3. Derive C from B, move C::g() to B, still no ambiguity.



// Name hiding: namespace example

namespace A
{
   struct X {};
   void g(X) { std::cout << " calling A::g() \n"; }

   namespace C {
      void g( ) { std::cout << "calling C:g() \n" ; }
      void j() {
         //using A::g;
         X x;
         g(x);
      }
   }
}

int main() {
   A::C::j();
}

// 1. add using A::g;
// 2. change g(int) to g(X)



/*
Name Lookup Sequence

 With namespaces:
 current scope => next enclosed scope => ... => global scope 

 To override the sequence:
    1. Qualifier or using declaration
    2. Koenig lookup

 With classes:
 current class scope => parent scope => ... => global scope

 To override the sequence:
 - Qualifier or using declaration

 Name hiding
 */