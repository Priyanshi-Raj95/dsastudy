#include<bits/stdc++.h>
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
static int idx=-1;
node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){  
        return 0;
    }
    node* currNode= new node(nodes[idx]);
    currNode->left= buildTree(nodes);
    currNode->right= buildTree(nodes);
    return currNode;
}
void kthHelper(node* root, int k, int currLevel){
    if(root ==NULL){
        return;
    }
    if(currLevel==k){
        cout<< root->data<<" ";
        return;
    }
    kthHelper(root->left, k, currLevel+1);
    kthHelper(root->right, k, currLevel+1);
}
void kthLevel(node* root, int k){
    kthHelper(root,k,1);
    cout<<endl;
}

int main(){
    vector<int>nodes= {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    kthLevel(root, 3);
    return 0;
}