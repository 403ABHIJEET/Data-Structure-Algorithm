#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isCycle(vector<vector<int>> &adj,vector<bool> &visited,int src,int parent) {
    visited[src] = true;
    for(auto i : adj[src]) {
        if(i!=parent) {
            if(visited[i] or (!visited[i] and isCycle(adj,visited,i,src))) 
                return true;
        }
    }
    return false;
}

int main() {
    int n,e; cin>>n>>e;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<e; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    bool cycle = false;
    for(int i=0; i<=n; i++) {
        if(!visited[i] and isCycle(adj,visited,i,-1)) {
            cycle = true;
            break;
        }
    }
    if(cycle) 
        cout<<"The cycle is Present in the graph."<<endl;
    else    
        cout<<"The cycle is not present in the graph"<<endl;
    return 0;
}