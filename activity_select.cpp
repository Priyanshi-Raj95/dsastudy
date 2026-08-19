#include<iostream>
#include<vector>
using namespace std;

int maxActivity(vector<int>st,vector<int>end){
    int count=1;
    int currEnd=end[0];
    for(int i=1;i<st.size();i++){
        if(st[i]>=currEnd){
            count++;
            currEnd=end[i];
        }
    }
    return count;
}
int main(){
    vector<int>st={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    cout<<"Max. activity to perform: "<< maxActivity(st,end);
    return 0;
}