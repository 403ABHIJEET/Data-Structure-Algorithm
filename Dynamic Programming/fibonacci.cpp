#include<iostream>
using namespace std;

const int N = 1e6;
long long dp[N];

long long fibonacci(int n) {
    if(n==1 || n==2)
        return 1;
    if(dp[n]!=-1)
        return dp[n];                              //! Tabulation Method
    dp[n] =  fibonacci(n-1)+fibonacci(n-2);
    return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    for(int i=0; i<N; i++)
        dp[i] = -1;
    int n; cin>>n;
    cout<<fibonacci(n)<<endl;
    return 0;
}