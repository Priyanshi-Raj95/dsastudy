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
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt= height(root->left);
    int rightHt= height(root->right);
    int currHt= max(leftHt,rightHt) +1;
    return currHt;
}
int main(){
     vector<int>nodes={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodes);
    int height_of_tree = height(root);
    cout<<"Height of the tree : "<<height_of_tree;
    return 0;
}