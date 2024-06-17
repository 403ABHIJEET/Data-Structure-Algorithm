#include<iostream>
#include<vector>
using namespace std;

int v,e;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> component;

int get_comp(int idx) {
    if(visited[idx])
        return 0;
    visited[idx] = true;
    int ans = 1;
    for(auto i : adj[idx]) {
        if(!visited[i]) {
            ans += get_comp(i);
            visited[i] = true;
        }
    }
    return ans;
}

int main() {
    cin>>v>>e;
    adj = vector<vector<int>>(v+1);
    visited = vector<bool>(v+1);
    for(int i=0; i<e; i++) {
        int n,m; cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    for(int i=0; i<=v; i++) {
        if(!visited[i])
            component.push_back(get_comp(i));
    }
    cout<<endl;
    for(auto i : component) {
            cout<<i<<endl;
    }
    return 0;
}