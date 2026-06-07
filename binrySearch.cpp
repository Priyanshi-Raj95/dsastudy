#include <iostream>
using namespace std;

int binarysrch(int n, int *arr, int key){
    int st=0;int end=n-1;
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            st= mid+1;
        }
        else{
            end= mid-1;
        }
    }
    return -1;
}
int main(){
    int n=8;
    int key;
    cout<<"Enter key : ";
    cin>>key;
    int arr[]= {2,4,6,8,10,12,14,16};
    cout<<"Element found at index : ";
    cout<< binarysrch(n,arr,key);
    return 0;
}