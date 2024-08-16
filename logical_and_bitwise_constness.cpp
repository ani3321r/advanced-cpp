#include<iostream>
#include<vector>
using namespace std;

class BigArray{
    vector<int> v;
    //mutable int accessCntr; //by making it mmutable, the variable can be changed in a const function
    int accessCntr;

    int* v2; //int array
public:
    //logical constness
    int getItem(int index) const{
        //accessCntr++; when we use mutable
        const_cast<BigArray*>(this)->accessCntr++; //when we use int we need to cast it
        return v[index];
    }

    void setV2Item(int index, int x) const {
        *(v2+index) = x;
    } //an array can also be updated be this process, due to its bitwise constness
};

int main(){
    BigArray b;
}