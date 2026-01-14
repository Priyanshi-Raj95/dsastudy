#include <iostream>
#include <cstring>
using namespace std;

void upper(char word[], int n){
    for(int i = 0;i<n;i++){
        char ch = word[i];
        if(ch >='A' && ch<='Z'){
            continue;
        }
        else{
            word[i] = ch-'a' + 'A';
        }
    }

}
void lower(char word[],int n){
    for(int i =0;i<n;i++){
        char ch = word[i];
        if(ch>='a' && ch<='z'){
            continue;
        }
        else{
            word[i] = ch-'A' + 'a';
        }
    }
}
int main(){
    //conversion into uppercase
    char word[] = "PriyANSHI";
    upper(word,strlen(word));
    cout<<"Uppercase word = "<<word<<endl;

    lower(word,strlen(word));
    cout<<"Lowercase word = "<<word<<endl;
    return 0;
}