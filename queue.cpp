#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class Queue{
    node *head;
    node *tail;
    public:
    Queue(){
        head=tail=NULL;
    }
    void push(int data){
        node *Newnode= new node(data);
        if(head==NULL){
            head=tail=Newnode;
        }else{
            tail->next=Newnode;
            tail=Newnode;
        }
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty.";
            return;
        }
        node *temp=head;
        head=head->next;
        delete temp;
    }
    int front(){

        if(empty()){
            cout<<"Queue is empty.";
            return -1;
        }
        return head->data;
    }
    bool empty(){
        return head==NULL;
    }
};

int main(){
    Queue q;
     q.push(1);
     q.push(2);
     q.push(3);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}