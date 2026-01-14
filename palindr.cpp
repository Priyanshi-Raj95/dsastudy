#include <iostream>
#include <cstring>
using namespace std;

bool palindrome(char str[], int n){
    int st=0,end = n-1;
   while(st<end){
    if(str[st++] != str[end--]){
        cout<<"not a palindrome";
        return false;
    }
   }
   cout<<"valid palindrome";
   return true;

}

int main(){
    
    char word[50];
    cin>>word;
    cout<<"Word is : "<<word<<endl;

    palindrome(word,strlen(word));
    return 0;
}