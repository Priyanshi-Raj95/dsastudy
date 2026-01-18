#include <iostream>
#include <vector>
using namespace std;


int main(){ 
    int n,target;
    cout<<"enter no of elements : ";
    cin>>n;

    vector<int> v;
    
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);

    }
    
    cout<<"Enter the target : ";
    cin>>target;
    bool found = false;
    for(int i =0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i] + v[j] == target){
                cout<<v[i]<<" , "<<v[j]<<endl;
                found = true;
            }
        }
    }
    if(!found){
        cout<<"Pair not found";
    }
    return 0;
}  