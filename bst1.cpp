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
// insert in BST
node* insert(node* root, int val){
    if(root==NULL){
        root= new node(val);
        return root;
    }
    if(val<root->data){
        root->left= insert(root->left,val);
    }
    else{
        root->right= insert(root->right,val);
    }
    return root;
}
static int idx=-1; 
node* buildBST(int arr[], int n){
    node* root= NULL;
    for(int i=0;i<n;i++){
        root= insert(root,arr[i]);
    }
    return root;
}
void inorder(node *root){ // inorder
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//search in BST
bool search(node* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data >key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}
//Inorder Successor
node* getInorderSuccessor(node* root){
    while(root->left !=NULL){
        root=root->left;
    }
    return root;
}
//delete a node 
node* delNode(node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(val < root->data){
    root->left = delNode(root->left,val);
    }else if(val > root->data){
        root->right= delNode(root->right, val);
    }else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left ==NULL || root->right==NULL){
            return root->left== NULL?root->right:root->left;
        }
        node* IS= getInorderSuccessor(root->right);
        root->data= IS->data;
        root->right= delNode(root,IS->data);
        return root;
    }
    return root;
}
//print in range
void printInRange(node* root, int st,int end){
    if(root==NULL){
        return;
    }
    if(st<=root->data && root->data<=end){ //case1
        printInRange(root->left,st,end);
        cout<<root->data<<" ";
        printInRange(root->right,st,end);
    }else if(root->data<st){  //case2
        printInRange(root->right,st,end);
    }
    else{  //case3
        printInRange(root->left,st,end);
    }
}
//root to leaf path print
void printPath(vector<int>path){
    cout<<"Path :";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathHelper(node* root, vector<int> &path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
       printPath(path);
       path.pop_back();
       return;
    }
    pathHelper(root->left, path);
    pathHelper(root->right, path);
    path.pop_back();
}
void rootToLeaf(node* root){
    vector<int>path;
    pathHelper(root,path);
}
// validate BST
bool validateHelper(node* root, node* min, node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && min->data>root->data){
        return false;
    }
    if(max!=NULL && root->data>max->data){
        return false;
    }
    return validateHelper(root->left, min,root) &&
    validateHelper(root->right, root, max);
}
bool validateBST(node* root){
    return validateHelper(root, NULL, NULL);
}
int main(){
    int arr[6]={5,1,3,4,2,7};
    int arr1[9]={8,5,3,1,4,6,10,11,14};
    node* root= buildBST(arr,6);
    node* roots = buildBST(arr1,9);
    inorder(root);
    cout<<endl;
    cout<<search(root, 5)<<endl;
    cout<<"Tree before deletion: ";
    inorder(root);
    cout<<endl;
    delNode(root,4);
    cout<<"After deletion tree will be: ";
    inorder(root);
    cout<<endl<<"Elements in range are: ";
    printInRange(roots,5,12);
    cout<<endl;
    rootToLeaf(roots);
    cout<<boolalpha<<validateBST(root);
    return 0;
}