#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreater(vector<int>v,vector<int>ans){
    stack<int>s;
    int idx=v.size()-1;
    ans[idx]= -1;
    s.push(v[idx]);
    for(int i=idx-1;i>=0;i--){
        int curr=v[i];
        while(!s.empty() && curr>=s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        
        s.push(curr);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v={6,8,0,1,3};
    vector<int>ans={0,0,0,0,0};
    nextGreater(v,ans);
    return 0;
}