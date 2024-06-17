#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<string> ans;
    void find(vector<vector<int>> &m,int i,int j,string curr) {
        if(i==m.size()-1 && j==m.size()-1 && m[i][j]!=0) {
            ans.push_back(curr);
            return;
        }
        if(i==m.size() || j==m.size() || m[i][j]==0)
            return;
        curr += 'D';
        find(m,i+1,j,curr);
        curr.pop_back();
        curr += 'R';
        find(m,i,j+1,curr);
        curr.pop_back();
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string curr = "";
        find(m,0,0,curr);
        return ans;
    }   
};

int main() {
    int n; cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(auto i : v) {
        for(auto j : i)
            cin>>j;
    }
    Solution s1;
    vector<string> ans = s1.findPath(v,n);
    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}