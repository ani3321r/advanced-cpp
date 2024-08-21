#include<iostream>
#include <synch.h>
#include <mutex>

using namespace std;

/* Resource Acquisition is Initialization (RAII) 
    Use objects to manage resources: 
    memory, hardware device, network handle, etc.
*/

mutex_t mu; 

void functionA()
{
    mutex_lock( &mu );
    mutex_unlock( &mu );
}

class Lock {
    private:
        mutex_t* m_pm;
    public:
        explicit Lock(mutex_t *pm) { mutex_lock(pm); m_pm = pm;};  
        ~Lock() { mutex_unlock(m_pm); };
}

void functionA()
{
   Lock mylock(&mu);
}  // The mutex will always be released when mylock is destroied from stack

//The only code that can be guaranteed to be executed after exception is 
//thrown are the destructor of objects residing on the stack.

//Resource management therefore needs to be tied to the lifespan of 
//suitable objects in order to gain automatic deallocation and reclamation.


int function_A() {
   std::tr1::shared_ptr<dog> pd(new dog()); +
} // The dog is destructed when pd goes out of scope (no more pointer
  // points to pd).

class dog;
class Trick;
void train(tr1::shared_ptr<dog> pd, Trick dogtrick);
Trick  getTrick();

int main() {
   tr1::shared_ptr<dog> pd(new dog());
   train(pd, getTrick());
}


// What happens in train()'s parameter passing:
// 1. new dog();
// 2. getTrick();
// 3. construct tr1::shared_ptr<dog>.
// The order of these operations are determined by compiler.


// Conclusion: Don't combine storing objects in shared pointer with other statement.
/*
Lock L1(&mu);
Lock L2(L1);
*/
    

//s1

// Prohibit copying. To see how to disallow copy constructor and copy 
// assignment operator from being used, watch my another session: 
// Disallow Compiler Generated Functions. 

//s2

//Reference-count the underlying resource by using tr1::shared_ptr
/*
template<class Other, class D> shared_ptr(Other * ptr, D deleter);

// The default value for D is "delete", e.g.:
	std::tr1::shared_ptr<dog> pd(new dog());
*/


/*
class Lock {
    private:
        std::tr1::shared_ptr<mutex_t> pmutex;
    public:
        explicit Lock(mutex_t *pm):pmutex(pm, mutex_unlock) { 
            mutex_lock(pm); 
        // The second parameter of shared_ptr constructor is "deleter" function.
        }; 
    };

Lock L1(&mu);
Lock L2(L1);
*/