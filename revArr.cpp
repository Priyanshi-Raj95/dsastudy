#include <iostream>
#include <cstring>
using namespace std;

void reverse(char word[], int n){
    int st=0,end = n-1;
   while(st<end){
      swap(word[st],word[end]);
      st++;
      end--;
   }

}

int main(){
    
    char word[50];
    cin>>word;
    cout<<"Before reversing : "<<word<<endl;
    reverse(word,strlen(word));
    cout<<"After reversing : "<<word<<endl;
    return 0;
}