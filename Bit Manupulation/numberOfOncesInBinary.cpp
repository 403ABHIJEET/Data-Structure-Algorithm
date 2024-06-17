#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    if(n==0) 
        cout<<0<<endl;
    else {
        int mask = n & (n-1);
        int count = 1;
        while(mask!=0) {
            mask = mask & (mask-1);
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}