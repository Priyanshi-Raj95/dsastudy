#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int  data){
        this->data=data;
        left=right=NULL;
    }
};
static int idx=-1;
node *buildTree(vector<int>nodes){ // tree building
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    node* currNode= new node( nodes[idx]); 
    currNode->left=buildTree(nodes); //left subtree
    currNode->right=buildTree(nodes); //right subtree
    return currNode;
}
void inorder(node *root){ // inorder
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root){ //post order
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void level_order(node* root){ //level order 1st type 
    if(root==NULL){
        return;
    }
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        node* curr= Q.front();
        Q.pop();
        cout<<curr->data<<" ";
        if(curr->left !=NULL){
            Q.push(curr->left);
        }
        if(curr->right !=NULL){
            Q.push(curr->right);
        }
    }
    cout<<endl; 
}
void level_order_2(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*curr= q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL); //to track next line
        }else{
            cout<<curr->data<<" ";
            if(curr->left !=NULL){
                q.push(curr->left);
            }
            if(curr->right !=NULL){
                q.push(curr->right);
            }
        }
    }
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    cout<<"For inorder travesal nodes are : ";
    inorder(root);
    cout<<endl;
    cout<<"For postorder travesal nodes are : ";
    postorder(root);
    cout<<endl;
    cout<<"For level order travesal nodes are : ";
    level_order(root);
    cout<<"For level order 2 travesal nodes are : "<<endl;
    level_order_2(root);
    return 0;
}