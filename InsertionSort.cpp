#include<iostream>
using namespace std;
void InsertionSort(int n,int *arr){
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    cout<<"Array after Sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n=6;
    int arr[]={5,6,3,1,4,2};
    cout<<"Array before Sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    InsertionSort(n,arr);
    return 0;
}