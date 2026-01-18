#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int target){
    int st =0,end = arr.size()-1;
    int currSum =0;
    vector<int>v;

    while(st<end){
        currSum = arr[st]+ arr[end];
        if(currSum == target){
            v.push_back(st);
            v.push_back(end);
            return v;
        }
        else if(currSum< target){
            st++;
        }
        else if(currSum>target){
            end--;
        }
    }
    return v;
}
int main(){ 
    vector<int> v1 = {2,7,11,15};
    int target;
    cout<<"Enter target : ";
    cin>>target;
    cout<<v1.size()<<endl;
    vector <int>v= pairSum(v1,target);
    cout<<v[0]<<","<<v[1]<<endl;

    return 0;
}   