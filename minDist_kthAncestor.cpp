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
node* lca(node* root, int n1,int n2){
    if(root ==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    node* leftLCA= lca(root->left, n1,n2);
    node* rightLCA= lca(root->right, n1,n2);

    if(leftLCA !=NULL && rightLCA!= NULL){
        return root;
    }
    return leftLCA ==NULL ? rightLCA : leftLCA;
}
int dist(node* root, int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftDist= dist(root->left,n);
    if(leftDist != -1){
        return leftDist+1;
    }
    int rightDist= dist(root->right,n);
    if(rightDist != -1){
        return rightDist+1;
    }
    return -1;
}
int minDist(node* root, int n1, int n2){
    node* LCA = lca(root, n1, n2);
    int dist1= dist(LCA,n1);
    int dist2= dist(LCA,n2);
    int result= dist1+dist2;
    return result;

}
int kth_ancestor(node* root, int node, int k){
    if(root==NULL){
        return -1;
    }
    if(root->data== node){
        return 0;
    }
    int leftDist= kth_ancestor(root->left, node, k);
    int rightDist= kth_ancestor(root->right, node, k);
    if(leftDist==-1 && rightDist==-1){
        return -1;
    }
    int validVal = leftDist ==-1 ? rightDist:leftDist;
    if(validVal+1 ==k){
        cout<<"Kth Ancestor: "<< root->data<<endl;
    }
    return validVal+1;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    int n1=4,n2=6;
    cout<<"Minimum distance between two nodes: "<<minDist(root, n1, n2);
    cout<<endl;
    int node=5, k=2;
    kth_ancestor(root, node, k);
    return 0;
}