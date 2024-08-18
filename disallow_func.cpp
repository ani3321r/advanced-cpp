#include<iostream>
#include<vector>
using namespace std;


//this will not work as the destructor is private 
/*
class openFile{
    public:
        openFile(string filename) {cout << "open a file " << filename <<endl;}
        g(openFile& f) {openFile f2(f);}
    private:
        openFile(openFile& rhs);
        openFile& operator=(const openFile& rhs);
        void writeline(string str);
        ~openFile(){cout << "openfile destructed " << endl;}    
};

int main(){
    openFile f(string("file"));// f is out of scope 

    openFile f2(f);
}
*/

//the way to use a private destructor

class openFile{
    public:
        openFile(string filename) {cout << "open a file " << filename <<endl;}
        void destroyMe() {delete this;}
    private:
        ~openFile(){cout << "openfile destructed " << endl;}    
};

int main(){
    openFile* f = new openFile(string("file"));
    f->destroyMe();
}

//it can only be destroyed on heap and not on stack, this sometimes is useful with the 
//stack overflow issues, where we can use a private destructor