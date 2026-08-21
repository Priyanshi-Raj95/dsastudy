#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
static int idx=-1;
Node *buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode= new Node( nodes[idx]); 
    currNode->left=buildTree(nodes); //left subtree
    currNode->right=buildTree(nodes); //right subtree
    return currNode;
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCt=count(root->left);
    int rightCt=count(root->right);
    return leftCt+rightCt+1;
}
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    int Sum=leftSum+rightSum+root->data;
    return Sum;
}
int main(){
     vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Count of nodes : "<<count(root);
    cout<<endl;
    cout<<"Sum of nodes : "<<sum(root);
    return 0;
}