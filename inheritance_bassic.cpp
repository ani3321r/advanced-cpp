#include<iostream>
#include<memory>
#include<string>
using namespace std;

//Public, Protected, Private Inheritance 

class B { 
};
class D_priv : private   B { };
class D_prot : protected B { };
class D_pub : public    B { };

/*
They specifies different access control from the derived class to the base class.

Access Control:
1. None of the derived classes can access anything that is private in B. 
2. D_pub inherits public members of B as public and the protected members of B as 
   protected
3. D_priv inherits the public and protected members of B as private. 
4. D_prot inherits the public and protected members of B as protected. 

Casting:
1. Anyone can cast a D_pub* to B*. D_pub is a special kind of B.
2. D_priv's members and friends can cast a D_priv* to B*.
3. D_prot's members, friends, and children can cast a D_prot* to B*.

Note: Only public inheritance indicates a is-a relationship.

*/

/* Detailed Example */
/*
class B { 
   public:
      void f_pub() { cout << "f_pub is called.\n"; }
   protected:
      void f_prot() { cout << "f_prot is called.\n"; }
   private:
      void f_priv() { cout << "f_priv is called.\n"; }
};

class D_pub : public B { 
   public:
      void f() { 
         f_pub();   // OK. D_pub's public function
         f_prot();  // OK. D_pub's protected function
         f_priv();  // Error. B's private function 
      }
};

class D_priv : private   B { 
   public:
   using B::f_pub;
      void f() {
         f_pub();   // OK. D_priv private function
         f_prot();  // OK. D_priv private function
         f_priv();  // Error. B's private function 
      }
};

int main() {
   D_pub D1;
   D1.f_pub();  // OK. f_pub() is D_pub's public function.

   D_priv D2;
   D2.f_pub();  // Error. f_pub() is D_priv's private function.

   B* pB = &D1;  // OK
   pB = &D2;     // Error
}
*/

// in D_prot, after public, add:  using B::f_pub;   the error goes away.

//  public inheritance: is-a relation, eg., D_pub is-a kind of a B. 
//  private inheritance: similar to has-a relation.

class Ring {
   virtual tremble();
   public:
   void tinkle() { tremble(); }
};

// Composition 
class Dog {
   Ring m_ring;
   public:
   void tinkle() {m_ring.tinkle();}  // call forwarding
};


// Private Inheritance
class Dog_Priv : private Ring {
   public:
   using Ring::tinkle;
};

/*
 composition's advantage: e.g., 2 rings, switchable ring.
 private inheritance's advantage: more elegant polymorphism.

 E.g. in class ring, add virtual function: tremble(), which is
    used in tinkle().
 */