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
//Approach 1 O(n), O(n)
bool rootToNodePath(node* root, int n, vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    int isLeft= rootToNodePath(root->left, n, path);
    int isRight= rootToNodePath(root->right, n, path);
    if(isLeft || isRight){
        return true;
    }
    path.pop_back();
    return false;
}
int lca(node* root, int n1, int n2){
    vector<int>path1;
    vector<int>path2;
    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);
    int lca=-1;
    for(int i=0,j=0;i<path1.size(),j<path2.size(); i++,j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;
}
//Approach 2 O(n), O(1)
node* lca2(node* root, int n1,int n2){
    if(root ==NULL){
        return NULL;
    }
    if(root->data ==n1 || root->data==n2){
        return root;
    }
    node* leftLCA= lca2(root->left, n1,n2);
    node* rightLCA= lca2(root->right, n1,n2);

    if(leftLCA !=NULL && rightLCA!= NULL){
        return root;
    }
    return leftLCA ==NULL ? rightLCA : leftLCA;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    int n1=4,n2=5;
    cout<<"LCA using approach1 : "<<lca(root, n1,n2);
    cout<<endl;
    cout<<"LCA using approach2 : "<<lca2(root,n1,n2)->data;
    return 0;
}