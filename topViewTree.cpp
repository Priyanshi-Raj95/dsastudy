#include<iostream>
#include<vector>
#include<map>
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
void topView(node* root){
    queue<pair<node*, int>> q; //(node, Hor. Dist.)
    map<int, int> m;  //(HD, node->data)
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node*, int> curr= q.front();
        q.pop();

        node* currNode= curr.first;
        int currHD= curr.second;
        if(m.count(currHD)==0){
            m[currHD] = currNode->data;
        }
        if(currNode->left !=NULL){
            pair<node*, int> left = make_pair(currNode->left, currHD-1);
            q.push(left);
        }
        if(currNode->right !=NULL){
            pair<node*, int> right = make_pair(currNode->right, currHD+1);
            q.push(right);
        }
    }
    for(auto it: m){
        cout<< it.second<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root= buildTree(nodes);
    topView(root); 
    return 0;
}