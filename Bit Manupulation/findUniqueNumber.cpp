#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int xorSum = 0;
    for(int i=0; i<n; i++) 
        xorSum = xorSum^arr[i];
    cout<<xorSum<<endl;
    return 0;
}