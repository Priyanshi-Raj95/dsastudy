#include<iostream>
using namespace std;
void selectionSort(int n, int *arr){
   for(int i=0;i<n-1;i++){
     int minidx=i;
     for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minidx]){
            minidx=j;
        }
     }
         swap(arr[i],arr[minidx]);
   }
   cout<<"Array after sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n=6;
    int arr[]={5,3,6,2,1,4};
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionSort(n,arr);
    return 0;
}