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
    //------bipartite graph-------
    bool isBipartite(){
        queue<int>q;
        vector<bool>vis(V,false);
        vector<int>color(V,-1);

        q.push(0);
        color[0]=0;
        while(q.size()>0)
        {
            int curr= q.front();
            q.pop();
            for(int v:l[curr]){
                if(!vis[v]){
                    vis[v]=true;
                    color[v]=1-color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    //------all paths print------
    void pathHelper(int src, int dest, vector<bool>&vis, string path){
        if(src==dest){
            cout<<path <<dest<<endl;
            return;
        }
        vis[src]=true;
        path+=to_string(src);
        for(int v: l[src]){
            if(!vis[v]){
                pathHelper(v,dest,vis,path);
            }
        }
        path= path.substr(0,path.size()-1);
        vis[src]=false;
    }

    void allPath(int src,int dest){
        vector<bool>vis(V,false);
        string path="";
        pathHelper(src,dest,vis,path);
    }
};
int main(){
    Graph graph(6,false);
    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);
    if(graph.isBipartite()){
        cout<<"It is bipartite graph.";
    }else{
        cout<<"It is not bipartite graph.";
    }
    cout<<endl;
    graph.allPath(5,1);
    return 0;
}