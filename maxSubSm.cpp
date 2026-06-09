#include<iostream>
#include<climits>
using namespace std;
//Bruteforce approach(n^3)
void subarSumBF(int n, int *arr){
    int maxSum= INT_MIN;
    for(int st=0;st<n;st++){
        for(int end = st;end<n;end++){
            int currSum =0;
            for(int i=st;i<=end;i++){
                currSum+=arr[i];
            }
            //cout<<currSum<<", ";
            maxSum= max(maxSum,currSum);
        }
    }
    cout<<"Maximum sum of subarray using BF is : "<<maxSum;
}
// Slightly optimized(n^2)
void subarSumSO(int n, int *arr){
    int maxSum= INT_MIN;
    for(int st=0;st<n;st++){
        int currSum =0;
        for(int end = st;end<n;end++){
            currSum +=arr[end];
            maxSum= max(maxSum,currSum);
        }

    }
    cout<<"Maximum sum of subarray using SO is : "<<maxSum;
}
//Kadane's Algorithm(n)
void subarSumKA(int n, int *arr){
    int maxSum=INT_MIN;
    int currSum =0;
    for(int i=0;i<n;i++){
        currSum +=arr[i];
        maxSum = max(currSum,maxSum);
        if(currSum<0){
            currSum=0;
        }
    }
    cout<<"Maximum sum of subarray using KA is : "<<maxSum;
}
int main(){
    int n=6;
    int arr[]={2,-3,6,-5,4,2};
    subarSumBF(n,arr);
    cout<<endl;
    subarSumSO(n,arr);
    cout<<endl;
    subarSumKA(n,arr);
    return 0;
}