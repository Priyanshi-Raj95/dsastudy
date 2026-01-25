#include<iostream>
#include<vector>
using namespace std;
//factorial
int func(int n){
    if(n==0){
        return 1;//base case
    }

    return n* func(n-1);
}
//decreasing order
void print(int n){
    if(n ==0){
        return;//base case
    }
    std :: cout<<n<<" ";
    print(n-1);
}
//sum of n numbers
int sum(int n){

    if(n == 1){
        return 1; //base case
    }
    
    return n + sum(n-1);
    
}
//nth fibonacci
int fib(int n){
    if(n ==0 || n ==1 ){
        return n;//base case
    }
    return fib(n-1) + fib(n-2); 
}
//check if array is sorted
bool isSorted(int *arr,int n,int i){
    if(i == (n-1)){
        return true;//base case
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr,n,i+1);

}
//first occurence
int frstOcc(vector<int>v,int i, int target){
    if(i == v.size()){
        return -1;//base target
    }
    if(v[i] == target){
        return i;
    }
    return  frstOcc(v,i+1,target);
}
//last occurence
int lstOcc(vector<int>v,int i,int target){
    if(i == v.size()){
        return -1;
    }
    int idx = lstOcc(v,i+1,target);
    if(idx == -1 && v[i] == target){
        return i;
    }
    return idx;
}
// x power n
int pow(int x, int n){
    if(n == 0){
        return 1;//base case
    }
    int halfPow = pow(x,n/2);
    int halfPowsq = halfPow *halfPow;
    if(n %2 ==0){
        return halfPowsq;
    }
    else{
        return halfPowsq*x;
    }
}
int main (){
    std ::cout<<func(5)<<endl;
    print(5);
    std::cout<<endl;
    std::cout<<sum(5)<<endl;
    std::cout<<fib(6)<<endl;
    int arr[5] = {1,2,3,7,9};
    cout<<isSorted(arr,5,0)<<endl;//answer = 1(true)
    vector<int>v = {5,8,8,7,7,3};
    cout<<frstOcc(v,0,8)<<endl;
    cout<<lstOcc(v,0,7)<<endl;
    cout<<pow(2,5);
    return 0;
}

