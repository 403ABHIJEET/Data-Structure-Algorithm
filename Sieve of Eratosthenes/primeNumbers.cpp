#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    bool arr[n+1];
    for(int i=0; i<n; i++) 
        arr[i] = true;
    for(int i=2; i<=sqrt(n); i++) {
        for(int j=i*i; j<=n; j++) {
            if(j%i==0) arr[j] = false;
        }
    }
    for(int i=1; i<n+1; i++) {
        if(arr[i])
            cout<<i+1<<" ";
    }
    return 0;
}