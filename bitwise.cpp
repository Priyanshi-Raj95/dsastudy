#include <iostream>
using namespace std;

// Odd or Even
void oddOrEven(int num){
    if(!(num & 1)){
        cout<<"Even";
    }
    else{
        cout<<"Odd";
    }
}

// ith position in bits
int getIthBit(int num, int i){
    int bitmask = 1<<i;

    if(!(num& bitmask)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){ 
    oddOrEven(6);
    cout<<endl;
    int n;
    cin>>n;
    cout<<getIthBit(7,n);
    return 0;
}   