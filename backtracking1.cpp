# include<bits/stdc++.h>
using namespace std;
// SUBSETS
void printsub(string str,string subset){
    if(str.size() ==0){
        cout<<subset<<" ";
        return;
    }
    char ch = str[0];
    printsub(str.substr(1,str.size()-1), subset+ch);//yes choice
    printsub(str.substr(1,str.size()-1), subset); //no choice
}
//PERMUTATION
void permutation(string str, string ans){
    int n = str.size();
    if(n==0){
        cout<<ans <<" ";
        return;
    }
    for(int i=0;i<n;i++){
        char ch = str[i];
        string next = str.substr(0,i)+str.substr(i+1,n-i-1);
        permutation(next,ans +ch);
    }
}
int main(){
    string str = "abc";
    string subset = "";
    string ans = "";
    printsub(str,subset);
    cout<<"\n";
    permutation(str,ans);
    return 0;
}