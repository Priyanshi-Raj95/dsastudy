#include<iostream>
using namespace std;
void bubbleSort(int n, int *arr){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"\nNew Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){

    int n=6;
    int arr[]={5,4,1,3,2,6};
    cout<<"Array before Sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(n, arr);
    
    return 0;
}