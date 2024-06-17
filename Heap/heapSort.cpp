#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v,int n,int i) {
    int maxIdx = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && v[l]>v[maxIdx])
        maxIdx = l;
    if(r<n && v[r]>v[maxIdx])
        maxIdx = r;
    if(maxIdx!=i) {
        swap(v[i],v[maxIdx]);
        heapify(v,n,maxIdx);
    }
}

void heapSort(vector<int> &v) {
    int n = v.size();
    for(int i=n/2-1; i>=0; i--)
        heapify(v,n,i);
    for(int i=n-1; i>0; i--) {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) 
        cin>>v[i];
    heapSort(v);
    for(auto i: v)
        cout<<i<<" ";
}