#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

bool compare(pair<double,int>p1, pair<double,int>p2 ){
    return p1.first > p2.first;
}
int frac_knapsack(vector<int>val,vector<int>wt, int w){ //O(n+nlogn+n)
    int n=val.size();
    vector<pair<double,int>>ratio(n,make_pair(0.0,0));//pair(ratio,idx)
    for(int i=0;i<n;i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }
    sort(ratio.begin(), ratio.end(),compare); //O(nlogn)
    int ans=0;
    for(int i=0;i<n;i++){
        int idx= ratio[i].second;
        if(wt[idx]<=w){
            ans+=val[idx];
            w-=wt[idx];
        }else{
            ans+=ratio[i].first *w;
            w=0;
            break;
        }
    }
    cout<<"Max value = "<<ans<<endl;
    return ans;
}
int main(){
    vector<int>val={60,100,120};
    vector<int>wt={10,20,30};
    int w=50;
    frac_knapsack(val,wt,w);
    return 0;
}