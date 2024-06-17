#include <iostream>
using namespace std;

const int N = 1e6;

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    bool check[N];
    for(int i=0; i<n; i++) 
        check[i] = false;
    for(int i=0; i<n; i++) {
        if(arr[i]>=0) 
            check[arr[i]] = true;
    }
    int ans;
    for(int i=0; i<N; i++) {
        if(!check[i]) {
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}