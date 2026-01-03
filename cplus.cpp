#include<iostream>
#include <climits>
using namespace std;

void print(int *arr,int n){
    cout<<"After sorting : ";
    for(int i=0;i<n;i++){
        
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int *arr,int n){
    
    for(int i=0;i<n-1;i++){
        
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
    print(arr,n);

}
int main(){ 
    int arr[] ={5,4,1,3,2};
    int n = sizeof (arr)/sizeof(int);
    cout<<"Before sorting : ";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    bubbleSort(arr,n);
    
    return 0;
}  