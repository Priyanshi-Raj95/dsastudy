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

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
node* buildBST(int arr[], int st, int end){
    if(st>end){
        return NULL;
    }
    int mid=(st+end)/2;
    node* curr= new node(arr[mid]);
    curr->left=buildBST(arr, st, mid-1);
    curr->right=buildBST(arr,mid+1,end);
    return curr;
}
//BST to Balanced BST
node* BSTfromSortedVec(vector<int>arr, int st, int end){
    if(st>end){
        return NULL;
    }
    int mid=(st+end)/2;
    node* curr= new node(arr[mid]);
    curr->left=BSTfromSortedVec(arr, st, mid-1);
    curr->right=BSTfromSortedVec(arr,mid+1,end);
    return curr;
}
void getInorder(node* root, vector<int>&nodes){
    if(root==NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
node* balanceBST(node* root){
    vector<int>nodes;
    getInorder(root,nodes);
    return BSTfromSortedVec(nodes,0,nodes.size()-1);
}
int main(){
    int arr[7]={3,4,5,6,7,8,9};
    node* roots=buildBST(arr,0,6);
    preorder(roots);
    cout<<endl;
    node* root= new node(6);
    root->left=new node(5);
    root->left->left= new node(4);
    root->left->left->left= new node(3);

    root->right= new node(7);
    root->right->right= new node(8);
    root->right->right->right= new node(9);
    root= balanceBST(root);
    preorder(root);
    return 0;
}