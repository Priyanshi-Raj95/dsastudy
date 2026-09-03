#include<iostream>
#include<vector>
#include<queue>
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
void level_order(node* root){ 
    if(root==NULL){
        return;
    }
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        int n=Q.size();
        for(int i=0;i<n;i++){
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
    
}
int transform(node* root){
    if(root == NULL){
        return 0;
    }
    int leftOld= transform(root->left);
    int rightOld= transform(root->right);
    int currOld= root->data;
    root->data= leftOld+rightOld;
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    return currOld;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    transform(root);
    level_order(root);
    return 0;
}