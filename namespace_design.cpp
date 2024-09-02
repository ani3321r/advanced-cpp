#include<iostream>
#include<memory>
#include<string>

// Why Koenig Lookup?

// Example 1:
namespace A
{
   struct X {};
   void g( X ) { cout << " calling A::g() \n"; }
   void g( ) { cout << " calling A::g() \n"; }
}

int main() {
   A::X x1;
   g(x1);   // Koenig Lookup, or Argument Dependent Lookup (ADL)
   g();     // Error
}


// 1. The Practical Reason

   std::cout << "Hi.\n"; // calls std::operator<<

   std::cout std::<< "Hi.\n"; // calls std::operator<<
   std::operator<<(std:cout, "Hi,\n");



//Notes:
//std::cout std::<< "hello\n";
//std::operator<<(std::cout, "hello\n");



//  * 2. Theoretical Reason: 
//  * -- What is the interface of a class?

namespace A
{
   class C {
      public:
      void f() = 0;
      void g() = 0;
   };
   void h(C);
   ostream& operator<<( ostream&, const C& );
}
void j(C);

/*
 Definition of class: 
 	A class describes a set of data, along with the functions that operate 
 	on that data.
*/



//Note: 
//1. void h(C);
//2. ostream& operator<<( ostream&, const C& );
//3. void j(C);


/* 
 Engineering Principle: 
 1. Functions that operate on class C and in a same namespace with C are 
    part of C's interface.
 2. Functions that are part of C's interface should be in the same namespace
    as C.
*/

A::C c;
c.f();
h(c);


namespace A { 
   class C {}; 
   int operator+(int n, A::C) { return n+1; }
}


int main()
{
   A::C arr[3]; 
   std::accumulate(arr, arr+3, 0);  // return 3
}

// Defined in C++ standard library <numeric>
namespace std {
   template <class InputIterator, class T>
      T accumulate ( InputIterator first, InputIterator last, T init )
   {
     while ( first!=last )
       init = init + *first++; 
     return init;
   }
}