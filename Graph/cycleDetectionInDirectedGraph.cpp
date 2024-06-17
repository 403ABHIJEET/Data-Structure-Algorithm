#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isCycle(int src,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &stack) {
    stack[src] = true;
    if(!visited[src]) {
        visited[src] = true;
        for(auto i : adj[src]) {
            if(stack[i] or (!visited[i] and isCycle(i,adj,visited,stack))) 
                return true;
        }
    }
    stack[src] = false;
    return false;
}

int main() {
    int v,e; cin>>v>>e;
    vector<vector<int>> adj(v+1);
    for(int i=0; i<e; i++) {
        int n,m; cin>>n>>m;
        adj[n].push_back(m);
    } 
    bool cycle = false;
    vector<bool> stack(v+1,0);
    vector<bool> visited(v+1,false);
    for(int i=0; i<=v; i++) {
        if(!visited[i] and isCycle(i,adj,visited,stack)) {
            cycle = true;
            break;
        }
    }
    if(cycle) 
        cout<<"Cycle is present"<<endl;
    else    
        cout<<"Cycle is not present"<<endl;
    return 0;
}