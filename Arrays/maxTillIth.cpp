#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>n;
    int ans = -19999;
    for(int i=0; i<n; i++) {    
        if(ans<arr[i]) {
            ans = arr[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}