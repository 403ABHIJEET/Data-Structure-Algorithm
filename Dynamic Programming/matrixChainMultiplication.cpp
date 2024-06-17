#include <bits/stdc++.h> 
using namespace std;

map<pair<int,int>,int> dp;

int find(vector<int> &arr,int s,int e) {
    if(s==e)    
        return 0;
    if(dp.find({s,e})!=dp.end())
        return dp[{s,e}];
    int ans = INT_MAX;
    for(int k=s; k<e; k++) {
        int cost = find(arr,s,k) + find(arr,k+1,e) + (arr[s]*arr[k+1]*arr[e+1]);
        ans = min(ans,cost);
    }
    return dp[{s,e}] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return find(arr,0,arr.size()-2);
}

int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<matrixMultiplication(v,n)<<endl;
    return 0;
}