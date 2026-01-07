#include <iostream>
#include <algorithm>
using namespace std;


void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[8] = {1,4,1,3,2,4,3,7};
    int arr1[8] = {9,6,8,2,1,1,3,4};
    
    sort(arr,arr+8);//sorting of all elements in ascending order
    print(arr,8); 

    cout<<endl;

    sort(arr,arr+8,greater<int>());//sorting of all elements in descending order
    print(arr,8);
    

    return 0;
}