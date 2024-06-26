#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
int dp[N];

int minSquare(int n) {
    if(n>=0 && n<=3)
        return n;
    if(dp[n]!=INT_MAX)
        return dp[n];
    for(int i=1; i*i<=n; i++)
        dp[n] = min(dp[n],1+minSquare(n-i*i));
    return dp[n];
}

int main() {
    for(int i=0; i<N; i++)
        dp[i] = INT_MAX;
    int n; cin>>n;
    cout<<minSquare(n)<<endl;
    return 0;
}