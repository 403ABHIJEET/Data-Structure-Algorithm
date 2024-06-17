#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> ans;
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i : a)
        cin>>i;
    sort(a.begin(),a.end());
    do {
        ans.push_back(a);
    }
    while(next_permutation(a.begin(),a.end()));
    for(auto i: ans) {
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}