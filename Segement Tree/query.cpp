#include<iostream>
using namespace std;

const int N = 1e5+2;
int a[N], tree[4*N];

void build(int node,int st,int en) {
    if(st==en) {
        tree[node] = a[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node,int st,int en,int l,int r) {
    if(st>r || l>en)
        return 0;
    if(st>=l && en<=r)
        return tree[node];
    int mid = (st+en)/2;
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,en,l,r);
    return q1+q2;
}

int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    build(1,0,n-1);
    cout<<query(1,0,n-1,1,5)<<endl;
    return 0;
}