#include<iostream>
using namespace std;

int countPath(int n,int s,int e) {
    if(s==n-1 || e==n-1)
        return 1;
    if(s>n-1 || e>n-1)
        return 0;
    return countPath(n,s+1,e) + countPath(n,s,e+1);
}

int main() {
    int n; cin>>n;
    cout<<countPath(n,0,0)<<endl;
    return 0;
}