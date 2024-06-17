#include<iostream>
using namespace std;

bool getBit(int x,int pos) {
    return ((x & (1<<pos))!=0);
}

int setBit(int x,int pos) {
    return (x | (1<<pos));
}

int main() {
    int n; cin>>n;
    int arr[n];
    int result = 0;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<64; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(getBit(arr[j],i))
                sum++;
        }
        if(sum%3!=0)
            result = setBit(result,i);
    }
    cout<<result<<endl;
    return 0;
}