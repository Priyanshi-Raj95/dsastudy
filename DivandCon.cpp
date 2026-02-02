# include <iostream>
#include <vector>
using namespace std;
// MERGE SORT
void merge(int *arr,int st,int mid,int end){
    vector<int> temp;
    int i =st;
    int j = mid +1; 

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<= mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }

    for(int idx = st,x =0;idx<=end;idx++){
        arr[idx] = temp[x++];
    }
}
void mergeSort(int *arr, int st,int end){
    if(st>=end){
        return;  
    }
    int mid = st +(end - st)/2;
    mergeSort(arr,st,mid); //left half
    mergeSort(arr,mid+1,end);//right half

    merge(arr,st,mid,end); // conquer
}
void printArr(int *arr, int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// QUICK SORT
int partition(int *arr, int st,int end){
    int i = st-1, pivot = arr[end];
    for(int j = st;j<end;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
        
    }
    i++;
        swap(arr[i], pivot);
        return i;
}
void QuickSort(int arr[], int st,int end){
    if(st>=end){
        return;
    }
    int pivotIdx = partition(arr,st,end);
    QuickSort(arr,st,pivotIdx-1);//left half
    QuickSort(arr,pivotIdx+1,end);//right half

}
//Rotated sorted array
int Search(int *arr, int st, int end, int target){
    if(st>end){
        return -1;
    }
    int mid = st +(end -st)/2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[st]<= arr[mid]){//L1
        if(arr[st]<= target && target <arr[mid]){
            return Search(arr,st,mid-1,target);
        }
        else{
            return Search(arr,mid+1,end,target);
        }
    }
    else{//L2
        if(arr[mid]<= target && target <=arr[end]){
            return Search(arr,mid+1,end,target);
        }
        else{
            
            return Search(arr,st,mid-1,target);
        }
    }
}
int main(){
    int arr[6] = {6,3,7,5,2,4};
    int n =6;
    int arr1[7] = {4,5,6,7,0,1,2};
    int n1=7;
    mergeSort(arr,0,n-1);
    printArr(arr,n);
    cout<<endl;
    QuickSort(arr,0,n-1);
    printArr(arr,n);
    cout<<endl;
    cout<<"Index : "<<Search(arr1,0,n1 - 1, 0);
    return 0;
}