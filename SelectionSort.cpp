#include <iostream>
#include <climits>
using namespace std;

void print(int *arr,int n){
    cout<<"After sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void selecSort(int *arr,int n){
    
    for(int i=0;i<n-1;i++){
        int minIdx = i; //minimum index
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx =j;
            }
        }
        swap(arr[i],arr[minIdx]);
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
    selecSort(arr,n);
    
    return 0;
}  