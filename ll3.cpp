#include<bits/stdc++.h>
using namespace std;
class node{
public:
   int data;
   node * next;
   node* prev1;
   node(int val){
      data = val;
      next = NULL;
      prev1 =next = NULL;
   }
};
class List{
public:
    node* head;
    node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        node* newNode = new node(val);
        if(tail == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }    
    void push_back(int val){
        node*newNode1= new node(val);
        if(head == NULL){
            head = tail =newNode1;
        }else{
            tail->next = newNode1;
            tail = newNode1;
        }
    }
};
void printll(node* head){
        node* temp = head;
        while(temp !=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
}
void printdll(node* head){
        node* temp = head;
        while(temp !=NULL){
            cout<<temp->data<<"<->";
            temp = temp->next;
        }
        cout<<"NULL\n";
}
node* splitMid(node*head){
    node* slow = head;
    node* fast = head;
    node*prev = NULL;
    while(fast!=NULL && fast ->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev !=NULL){
        prev->next = NULL;//split at middle
    }
    return slow;//rightHead
}
node* reverse(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    while(curr !=NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}
node* zigzagll(node*head){
    node* rightHead = splitMid(head);
    node * rightHdRev = reverse(rightHead);
    //alternate merging
    node*left = head;
    node* right = rightHdRev;
    node* tail = right;
    while(left !=NULL && right != NULL){
        node* nextlft = left ->next;
        node* nxtrght = right->next;
        
        left->next = right;
        right->next = nextlft;
        tail = right;

        left = nextlft;
        right = nxtrght;
    }
    if(right!= NULL){
        tail->next = right;
    }
    return head;
}
class doublyll{
public:
    node* head;
    node* tail;

    doublyll(){
        head =tail =NULL;
    }
    void push_front(int value){
        node* newN = new node(value);

        if(head ==NULL){
            head = tail = newN;
        }else{
            newN->next = head;
            head->prev1 = newN;
            head = newN;
        }
    }
};
int main(){
    List ll;
    doublyll dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    
    printdll(dll.head);
    cout<<endl;
    ll.head = zigzagll(ll.head);
    printll(ll.head);
    return 0;
}