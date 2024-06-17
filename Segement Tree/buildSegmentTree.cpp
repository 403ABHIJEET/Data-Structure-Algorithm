#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+2;
int a[N],tree[4*N];

void build(int node,int s,int e) {
    if(s==e) {
        tree[node] = a[s];
        return;
    }
    int mid = (s+e)/2;
    build(2*node,s,mid);
    build((2*node)+1,mid+1,e);
    tree[node] = tree[2*node]+tree[2*node+1];
}

int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    build(1,0,n-1);
    for(int i=1; i<=15; i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    return 0;
}