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
void ReverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    ReverseStack(s);
    PushAtBottom(s,temp);

}
int main(){
    stack<int>st;
    st.push(30);
    st.push(20);
    st.push(10);
    cout<<"Before reversing the stack: ";
    printStack(st);
    ReverseStack(st);
    cout<<"After reversing the stack: ";
    printStack(st);
    return 0;
}