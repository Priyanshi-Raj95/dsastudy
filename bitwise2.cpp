#include <iostream>
#include <vector>
using namespace std;

// set ith bit
int setithBit(int num,int i){
    int bitMask = 1<<i;
    return (num | bitMask);

}

//clear ith bit
int clearithBit(int n,int i){
    int bitmask = ~(1<<i);
    return (n & bitmask);
}

// check for power of 2
bool check(int number){
    if(!(number & (number - 1))){
        return true;
    }
    else{
        return false;
    }
}
int main(){ 
    cout<<setithBit(6,3)<<endl;
    cout<<clearithBit(6,1)<<endl;
    cout<<check(9)<<endl;
    return 0;
}   