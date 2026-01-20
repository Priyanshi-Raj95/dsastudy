#include <iostream>
#include <vector>
using namespace std;

//update ith bit
void updateithBit(int n, int i, int value){
    n = n & ~(1<<i); // clear ith bit
    n = n | (value<<i);

    cout<<n<<endl;
}
//clear last i bits
void cleari(int n, int i ){
    int bitmask = (~0<<i);
    n = n& bitmask;
    cout<<n<<endl;
}
// count set bits
int count(int n){
    int count = 0;
    while(n>0){
        int lastDigit = n &1;
        count += lastDigit;

        n = n>>1;
    }
    cout<<count<<endl;
    return count;
}
int main(){ 
    
    updateithBit(7,2,0);
    cleari(15,2);
    count(10);
    return 0;
}   