#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
public:
    int V;
    list<int> *l;
    Graph(int V){
        this->V= V;
        l= new list<int> [V];
    }
    void addEdge( int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
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
    //------BFS------
    void bfs(){ //O(V+E)
        queue<int>q;
        vector<bool>vis(V,false);
        q.push(0);
        vis[0]=true;
        while(q.size() >0){
            int u= q.front();
            q.pop();
            cout<<u<<" ";

            list<int>neighbors= l[u]; //u----v
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v]= true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
    //-----DFS-----
    void dfs(int u, vector<bool>&vis){ //O(v+E)
        vis[u]=true;
        cout<<u<<" ";
        list<int> neighbors= l[u];
        for(int v: neighbors){
            if(!vis[v]){
                dfs(v,vis);
            }
        }
    }
    //-----HasPath-----
    bool hasPath(int src, int dest, vector<bool> &vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int>neighbors= l[src];
        for(int v: neighbors){
            if(!vis[v]){
                if(hasPath(v,dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph graph(7);
    // Undirected
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    
    graph.print();
    cout<<"BFS searching: ";
    graph.bfs();
    cout<<"DFS searching: ";
    vector<bool> vis(7,false);
    graph.dfs(0,vis);
    cout<<endl<<"HasPath: ";
    vector<bool>vis1(7,false);
    if(graph.hasPath(0,5, vis1)){
        cout<<"Path exists";
    }
    else{
        cout<<"Path doesn't exists";
    }
    return 0;
}