#include<iostream>
#include<stack>
using namespace std;

void PushAtBottom(stack <int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int temp=st.top();
    st.pop();
    PushAtBottom(st,val);
    st.push(temp);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main(){
    stack<int>st;
    st.push(30);
    st.push(20);
    st.push(10);
    cout<<"Original stack : ";
    printStack(st);
    
    PushAtBottom(st,40);
    cout<<"After pushing the value: ";
    printStack(st);
    return 0;
}