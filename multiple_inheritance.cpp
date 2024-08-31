#include<iostream>
#include<memory>
#include<string>
using namespace std;

//Multiple Inheritance


class InputFile {
   public:
   void read();
};

class OutputFile {
   public:
   void write();
};

class IOFile : public InputFile, public OutputFile {
};

int main() {
   IOFile f;
}

// Notes:
//   void open();
//   f.open();   
//Correction:
//f.Output::open();


class File {            //         File
   public:              //         /  \        -
   string name;         // InputFile  OutputFile
   void open();         //         \  /
};                      //        IOFile

class InputFile : virtual public File {
};                              
                                
class OutputFile : virtual public File {
};                              

class IOFile : public InputFile, public OutputFile {
};  // Diamond shape of hierarchy

int main() {
   IOFile f;
   f.open();   
   //f.InputFile::name = "File1";
   //f.OutputFile::name = "File2";
}

// Compile Error: Ambiguous call to open()
// f.InputFile::name  = "File1";
// f.OutputFile::name = "File2";

/*
class File {     
   public:      
   File(string fname);
};             

class InputFile : virtual public File {
   InputFile(string fname) : File(fname) {}
};                              
                                
class OutputFile : virtual public File {
   OutputFile(string fname) : File(fname) {}
};                              

class IOFile : public InputFile, public OutputFile {
   IOFile(string fname) : OutputFile(fname), InputFile(fname), File(fname) {} //the class containing most derived classes must contain the root class
};  

int main() {
   IOFile f;
}
*/

//reason to use multiple inheritance inspite of it being so difficult
/*
  Interface Segregation Principle
  
  Split large interfaces into smaller and more specific ones so that clients
  only need to know about the methods that are of interest to them.
 */

//example
/*
class Engineer {
   public:
   ...; // 40 APIs
};

class Son {
   public:
   ...; // 50 APIs
};

...

class Andy : public Engineer, Son {
   public:
   ...; // 500 APIs
};
*/


/*
  Pure Abstract Classes 

  Abstract Class: A class has one or more pure virtural functions.

  Pure Abstract Classes: 
  A class containing only pure virtual functions
    - no data 
    - no concrete functions
    - no private protected functions
 */

/*
class OutputFile {
   public:
   void write() = 0;
   void open() = 0;
};
*/


/*
 Summary:
 1. Multiple Inheritance is an important technique, e.g. ISP
 2. Derive only from PACs when using Multiple Inheritance.
 */
