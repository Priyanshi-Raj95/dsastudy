#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
public:
    int V;
    list<int> *l;
    bool isUndir;
    Graph(int V, bool isUndir=true){
        this->V= V;
        l= new list<int> [V];
        this->isUndir= isUndir;
    }
    void addEdge( int u, int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }
    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbors= l[u];
            cout<<u<<" : ";
            for(int v: neighbors){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    
    //-----Disconnected graph-----
    void dfsHelper(int u, vector<bool>&vis){ //O(v+E)      
        cout<<u<<" ";
        vis[u]=true;
        list<int> neighbors= l[u];
        for(int v: neighbors){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
            cout<<"  ";
        }
    }
    //-------Cycle detect(Undirected)----
    bool undirCycleHelper(int src, int par, vector<bool> &vis){
        vis[src]=true;
        for(int v: l[src]){
            if(!vis[v]){
                if (undirCycleHelper(v,src,vis)){
                    return true;
                }
            }else{
                    if(v !=par){
                        return true;
                    }
                }
        }
        return false;
    } 
    bool isCycleUndir(){
        vector<bool> vis(V,false);
        return undirCycleHelper(0,-1,vis);
    }
    //------Cycle detect(directed)------
    bool dirCycleHelper(int src, vector<bool>&vis, vector<bool> &recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int>neighbors= l[src];

        for(int v: neighbors){
            if(!vis[v]){
                if(dirCycleHelper(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    bool isCycleDir(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dirCycleHelper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph graph(4,false);
    // Undirected
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);
    
    cout<<"DFS : ";
    graph.dfs();
    cout<<endl;
    cout<<graph.isCycleUndir();
    cout<<endl<<graph.isCycleDir();
    return 0;
}