#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
static int idx= -1;
node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return 0;
    }
    node* currNode= new node(nodes[idx]);
    currNode->left= buildTree(nodes);
    currNode->right= buildTree(nodes);
    return currNode;
}
bool isIdentical(node* root1, node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }else if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    return isIdentical(root1->left, root2->left) &&
    isIdentical(root1->right, root2->right); 
}
bool isSubtree(node* root, node* subRoot){
    if(root==NULL && subRoot==NULL){
        return true;
    }else if(root==NULL || subRoot==NULL){
        return false;
    }
    if(root->data == subRoot->data){
        if(isIdentical(root, subRoot)){
            return true;
        }
    }
    int isLeftSubtree= isSubtree(root->left, subRoot);
    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }
    return true;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    node* subRoot= new node(2);
    subRoot->left= new node(4);
    subRoot->right= new node(5);
    if(isSubtree(root,subRoot)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}
