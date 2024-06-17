#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n; cin>>n;
    bool arr[n];
    for(int i=0; i<n; i++) 
        arr[i] = true;
    for(int i=2; i<=sqrt(n); i++) {
        for(int j=i*i; j<=n; j++) {
            if(j%i==0)
                arr[j] = false;
        }
    }
    int i = 1;
    while(n!=1) {
        if(arr[i] && n%(i+1)==0) {
            cout<<i+1<<endl;
            n /= (i+1);
        }
        else
            i++; 
    }
    return 0;
}