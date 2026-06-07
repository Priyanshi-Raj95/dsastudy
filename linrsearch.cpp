#include <iostream>
using namespace std;
int linearSearch(int n,int *arr,int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}
int main(){
    int n=8;
    int key;
    cout<<"Enter key : ";
    cin>>key;
    int arr[]={2,4,6,8,10,12,14,16};
    cout<<"Element is found at index : "<<linearSearch(n,arr,key);
    return 0;
}