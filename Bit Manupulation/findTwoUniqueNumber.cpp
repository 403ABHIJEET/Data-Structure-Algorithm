#include<iostream>
using namespace std;

int setbit(int n,int pos) {
    return ((n & (1<<n))!=0);
}

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int xorSum = 0;
    for(int i=0; i<n; i++)
        xorSum = xorSum^arr[i];
    int setBit = 0;
    int pos = 0;
    while(setBit!=1) {
        setBit = xorSum^1;
        pos++;
        xorSum = xorSum>>1;
    }
    int tempXor = xorSum;
    int newXor = 0;
    for(int i=0; i<n; i++) {
        if(setbit(arr[i],pos-1)) {
            newXor = newXor^arr[i]; 
        }
    }
    cout<<newXor<<endl;
    cout<<(tempXor^newXor)<<endl;
    return 0;
}