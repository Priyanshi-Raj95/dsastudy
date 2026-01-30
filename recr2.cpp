#include <iostream>
using namespace std;
//tiling problem
int tp(int n){
    if(n==0 || n==1){
        return 1;
    }
    //vertical
    int ans1 = tp(n-1);
    //horizontal
    int ans2 = tp(n-2);
    return ans1 + ans2;
}
//remove duplicates in string
void remDup(string str, string ans, int i, int map[26]){
    if(i == str.size()){
        cout<<"ans : "<<ans <<endl;
        return;
    }
    int mapIdx = (int)(str[i] - 'a');
    if(map[mapIdx] == true){//duplicate
        remDup(str,ans,i+1,map);
    }
    else{//not duplicate
        map[mapIdx] = true;
        remDup(str,ans + str[i],i+1,map);
    }
}
//friend pairing problem
int frndPair(int n){
    if(n==1 ||n==2){
        return n;
    }
    //single
    int a1 = frndPair(n-1);
    //pairing
    int a2 = (n-1)*frndPair(n-2);
    return a1+a2;
}
//binary string
void binStrin(int n, int lstPlace, string ans){
    if(n ==0){
        cout<<ans<<endl;
        return;
    }
    if(lstPlace != 1){
        binStrin(n-1,0,ans +'0');
        binStrin(n-1,1,ans + '1');
    }
    else{
        binStrin(n-1,0,ans + '0');
    }
}
int main(){
    int n;
    cin>>n;
    cout<<tp(n)<<endl;  
    string str = "Priyanshi";
    string ans = "";
    int map[26] = {false};
    remDup(str,ans,0,map);
    
    cout<<frndPair(3)<<endl;
    
    binStrin(3,0,ans);
    return 0;
}