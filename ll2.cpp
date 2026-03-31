#include<bits/stdc++.h>
using namespace std;
class node{
public:
   int data;
   node * next;

   node(int val){
      data = val;
      next = NULL;
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
//detecting cycle
bool isCycle(node* head){
        node* slow = head;
        node* fast = head;

        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                cout<<"Cycle exist\n";
                return true;
            }
        }
        cout<<"Cycle doesn't exist\n";
        return false;
}
//removing cycle
void removeCycle(node* head){
    isCycle(head);
    node *slow = head;
    node *fast = head;
    
    if(slow == head){
        while(fast->next !=slow){
            fast = fast->next;
        }
        fast ->next= NULL;
    }else{
        node * prev = fast;
        while(slow !=fast){
        slow = slow ->next;
        prev =fast;
        fast = fast->next;
        }  
        prev ->next = NULL;
    }
}
//merge sorting
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
node* merge(node* left, node* right){
    List ans;
    node* i=left;
    node* j= right;
    while(i!=NULL && j!=NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i !=NULL){
        ans.push_back(i->data);
        i = i->next;
    }
    while(j !=NULL){
        ans.push_back(j->data);
        j= j->next;
    }
    return ans.head;
}
node* mergeSort(node* head){
    if(head ==NULL || head ->next ==NULL){
        return head;
    }
    node* rightHead = splitMid(head);
    node* left = mergeSort(head);//left half
    node* right = mergeSort(rightHead);//right half
    return merge(left,right);
}
int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.tail->next = ll.head;
    isCycle(ll.head);
    removeCycle(ll.head);
    printll(ll.head);
    ll.head = mergeSort(ll.head);
    printll(ll.head);
    return 0;
}