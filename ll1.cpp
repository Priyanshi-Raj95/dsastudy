#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int value){
        data = value;
        next = NULL;
    }
    ~node(){
        if(next !=NULL){
            delete next;
            next = NULL;
        }
    }
};
class list{
public:
    node* head;
    node* tail; 
    list(){
        head = NULL;
        tail = NULL;
    }
    ~list(){
        if(head !=NULL){
            delete head;
            head = NULL;
        }
    }
    void push_front(int value){
        node* newN1 = new node(value);
        if(head ==NULL){
            head = tail = newN1;
        }
        else{
            newN1 ->next = head;
            head = newN1;

        }
    }
    void push_back(int value){
        node* newN2 = new node(value);
        if(head ==NULL){
            head = tail = newN2;
        }
        else{
            tail->next = newN2;
            tail = newN2;

        }
    }
    void printll(){
        node* temp = head;
        while(temp !=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
    void insert(int value,int pos){
        node* newN3 = new node(value);
        node* temp = head; 
        for(int i=0;i<pos-1;i++){
            if(temp == NULL){
                cout<<"INVALID position";
                return;
            }
            temp = temp->next;
        }
        newN3 ->next = temp ->next;
        temp ->next = newN3;
    }
};
int main(){
    list ll;
    ll.push_front(30);
    ll.push_front(20);
    ll.push_front(10);
    ll.push_back(40); 
    ll.printll();
    ll.insert(50,2);
    ll.printll();
    return 0;
}