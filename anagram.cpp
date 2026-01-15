#include <iostream>
#include <string>
using namespace std;

bool anagram(string str1,string str2){
    if(str1.length() != str2.length()){
        cout<<"not valid anagram";
        return false;
    }
    int count[26] = {0};
    for(int i =0;i<str1.length();i++){
        int idx = str1[i]-'a';
        count[idx]++;
    }
    for(int i =0;i<str2.length();i++){
        int idx = str2[i]-'a';
        if(count[idx] ==0){
            cout<<"not valid anagram\n";
            return false;
        }
        count[idx]--;
    }
    cout<<"valid anagram\n";
    return true;
}
int main(){
    string str1 ;
    cin>>str1;
    cout<<"Entered string : "<<str1<<endl;

    string str2 ;
    cin>>str2;
    cout<<"Second string : "<<str2<<endl;

    anagram(str1,str2);

    return 0;
}