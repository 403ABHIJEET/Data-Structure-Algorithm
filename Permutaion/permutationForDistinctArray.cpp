#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a,int idx) {
    if(idx==a.size()) {
        ans.push_back(a);
        return;
    }
    for(int i=idx; i<a.size(); i++) {
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }
}

int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v)
        cin>>i;
    permute(v,0);
    for(auto i : ans) {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }    
    return 0;
}