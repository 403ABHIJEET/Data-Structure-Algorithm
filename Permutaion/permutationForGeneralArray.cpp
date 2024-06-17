#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helper(vector<int> &a,vector<vector<int>> &ans,int idx) {
    if(idx==a.size()) {
        ans.push_back(a);
        return;
    }
    for(int i=idx; i<a.size(); i++) {
        if(i!=idx && a[i]==a[idx])
            continue;
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }
}

vector<vector<int>> permute(vector<int> a) {
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    helper(a,ans,0);
    return ans;
}

int main() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i: a)
        cin>>a[i];
    vector<vector<int>> res = permute(a);
    cout<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    } 
    return 0;
}