#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<int> adj[],int e) {
    bool visit[e];
    for(int i=0; i<e; i++)
        visit[i] = false;
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty()) {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i=0; i<adj[curr].size(); i++) {
            if(!visit[adj[curr][i]]) {
                q.push(adj[curr][i]);
                visit[adj[curr][i]] = true;
            }
        }
    } 
}

int main() {
    int e; cin>>e;
    vector<int> adjList[e+1];
    for(int i=0; i<e; i++) {
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    BFS(adjList,e+1);
    cout<<endl;
    return 0;
}