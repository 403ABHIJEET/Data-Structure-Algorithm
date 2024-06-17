#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<int> adj[],int n) {
    vector<int> ans;
    vector<int> indeg(n,0);
    vector<bool> visit(n,false);
    for(int i=0; i<n; i++) {
        for(int j=0; j<adj[i].size(); j++)
            indeg[adj[i][j]]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indeg[i]==0) {
            q.push(i);
            visit[i] = true;
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int i=0; i<adj[curr].size(); i++) 
            indeg[adj[curr][i]]--;
        for(int i=0; i<n; i++) {
            if(indeg[i]==0 && !visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
    return ans;
}

int main() {
    int n,e; cin>>n>>e;
    vector<int> adjList[n];
    for(int i=0; i<e; i++) {
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
    }
    vector<int> v = topologicalSort(adjList,n);
    for(auto i: v) 
        cout<<i<<" ";
    cout<<endl;
    return 0;
}