#include<bits/stdc++.h>
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
// size of larger BST in BT
class info{
public:    
    bool isBST;
    int min;
    int max;
    int size;
    info(bool isBST, int min, int max, int size){
        this->isBST= isBST;
        this->min= min;
        this->max= max;
        this->size= size;
    }
};
static int maxSize;
info* largerBST(node* root){
    if(root== NULL){
        return new info(true, INT_MAX, INT_MIN, 0);
    }
    info* leftInfo= largerBST(root->left);
    info* rightInfo= largerBST(root->right);

    int currMin= min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax= max(root->data, max(leftInfo->max, rightInfo->max));
    int currSize= leftInfo->size + rightInfo->size + 1;
    
    if(leftInfo->isBST && rightInfo->isBST && root->data >leftInfo->max
       && root->data < rightInfo->min){
        maxSize= max(maxSize, currSize);
        return new info(true, currMin, currMax, currSize);
    }
    return new info(false, currMin, currMax, currSize);
}
// merge two BSTs
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
void getInorder(node *root, vector<int>&nodes){ // inorder
    if(root==NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
node* mergeBST(node* root1, node* root2){
    vector<int>nodes1;
    vector<int>nodes2;
    vector<int>merged;

    getInorder(root1,nodes1);
    getInorder(root2,nodes2);
    int i=0,j=0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i]<nodes2[j]){
            merged.push_back(nodes1[i++]);
        }else{
            merged.push_back(nodes2[j++]);
        }
    }
    while(i<nodes1.size()){
        merged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        merged.push_back(nodes2[j++]);
    }
    return BSTfromSortedVec(merged,0,merged.size()-1);
}
int main(){
node* root= new node(50);
    root->left=new node(30);
    root->left->left= new node(5);
    root->left->right= new node(20);

    root->right= new node(60);
    root->right->left= new node(45);
    root->right->right= new node(70);
    root->right->right->left= new node(65);
    root->right->right->right= new node(80);

    largerBST(root);
    cout<<"MAx size: "<<maxSize<<endl;
    node* root1= new node(2);
    root1->left= new node(1);
    root1->right= new node(4);

    node* root2= new node(9);
    root2->left= new node(3);
    root2->right= new node(12);
    node* roots= mergeBST(root1, root2);
    preorder(roots);
    cout<<endl;
    return 0;
}