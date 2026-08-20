#include<bits/stdc++.h>
using namespace std;

int getMinChange(vector<int>coins, int v){
    int ans=0;
    int n=coins.size();
    for(int i=n-1;i>=0 && v > 0;i--){
        if(v>=coins[i]){
            ans+=v/coins[i];
            v=v%coins[i];
        }
    }
    cout<<"Min coins for change : "<<ans<<endl;
    return ans;
}
int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int v=599;

    getMinChange(coins,v);
    return 0;
}