#include <iostream>
#include <climits>
using namespace std;

void print(int *arr,int n){
    cout<<"After sorting the array  : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void countSort(int *arr,int n){
    
    int freq[100000] = {0};//range 
    int minValue = INT_MAX, maxVal = INT_MIN;
    
    for(int i=0;i<n;i++){
        minValue = min(minValue,arr[i]);
        maxVal = max(maxVal,arr[i]);
    }
    //1st step --O(n)
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    //2nd step --O(range)=max-min
    for(int i=minValue,j=0;i<=maxVal;i++){
        while(freq[i]>0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr,n);
}
int main(){ 
    int arr[] ={1,4,1,3,2,4,3,7 };
    int n = sizeof (arr)/sizeof(int);
    cout<<"Before sorting the array : ";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    countSort(arr,n);
    
    return 0;
}  