#include "singelton.cpp"
using namespace std;

int main(){
    Singleton s;
    Singleton::getCat()->meow();
}