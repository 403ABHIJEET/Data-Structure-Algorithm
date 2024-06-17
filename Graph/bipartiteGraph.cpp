#include<iostream>
#include<vector>
using namespace std;

bool isBipartite(vector<vector<int>> &adj,vector<bool> &visited,vector<char> &color) {
    
}

int main() {
    int v,e; cin>>v>>e;
    vector<vector<int>> adj(v+1);
    for(int i=0; i<v; i++) {
        int n,m; cin>>n>>m;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
    vector<bool> visited(adj.size(),false);
    vector<char> color(adj.size(),'N');
    if(isBipartite(adj,visited,color))
        cout<<"The graph is bipartite"<<endl;
    else    
        cout<<"The graph isn't bipartite"<<endl;
    return 0;
}