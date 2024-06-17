#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(vector<int> adj[],int e) {
    stack<int> st;
    bool visited[e];
    for(int i=0; i<e; i++)
        visited[i] = false;
    st.push(1);
    visited[1] = true;
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout<<curr<<" ";
        for(int i=0; i<adj[curr].size(); i++) {
            if(!visited[adj[curr][i]]) {
                st.push(adj[curr][i]);
                visited[adj[curr][i]] = true;
            }
        }
    }
}

int main() {
    int e; cin>>e; //e = 7
    vector<int> adj[e+1];
    /*1 2
      1 3
      2 4
      2 5
      2 6
      2 7
      3 7*/
    for(int i=0; i<e; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(adj,e+1);
    cout<<endl;
    return 0;
}