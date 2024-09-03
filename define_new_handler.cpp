#include<iostream>
#include<memory>
#include<string>
using namespace std;

//  Define Your Own New-handler
/*
 1. What is new-handler 

 New handler is a function invoked when operator new failed to allocate 
 memory. It's purpose is to help memory allocation to succeed.
   set_new_handler() installs a new handler and returns current new handler.
 */
void* operator new(std::size_t size) throw(std::bad_alloc) {
   while (true) {
      void* pMem = malloc(size);   // Allocate memory
      if (pMem) 
         return pMem;              // Return the memory if successful

      new_handler Handler = set_new_handler(0);  // Get new handler
      set_new_handler(Handler);

      if (Handler)
         (*Handler)();            // Invoke new handler
      else
         throw bad_alloc();       // If new handler is null, throw exception
   }
}
/* 
So the new-handler must to do one of following things:
1) Make more memory available.
2) Install a different new-handler.
3) Uninstall the new-handler (passing a null pointer).
4) Throw an exception bad_alloc or its descendent.
5) Terminate the program.
 */

int main() {
   int *pGiant = new int[10000000000L];
   delete[] pGiant;
}

// OUTPUT:
// terminate called after throwing an instance of 'std::bad_alloc'


void NoMoreMem() {
   std::cerr << "Unable to allocate memory, Bo." << endl;
   abort();
}
int main() {
   std::set_new_handler(NoMoreMem);
   int *pGiant = new int[10000000000L];
   delete[] pGiant;
}

// OUTPUT:
// Unable to allocate memory, Bo.


//2. Class specific new-handler

class dog {
   int hair[10000000000L];
   std::new_handler origHandler;
   public:
   static void NoMemForDog() {
      std::cerr << "No more memory for doggy, Bo." << endl;
      std::set_new_handler(origHandler); // Restore old handler
      throw std::bad_alloc;
   }
   void* operator new(std::size_t size) throw(std::bad_alloc) {
      origHandler = std::set_new_handler(NoMemForDog);  
      void* pV = ::operator new(size);   // Call global operator new
      std::set_new_handler(origHandler); // Restore old handler
      return pV;
   }
};


int main() {
   std::tr1::shared_ptr<dog> pd(new dog());
}

// Any problem
//
// Solution:
//    Duplicate set_new_handler in NoMemForDog()