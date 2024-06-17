#include<iostream>
using namespace std;

int main() {
    int cnt = 1;
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cout<<cnt<<" ";
            cnt++;
        }
        cout<<endl;
    }
    return 0;
}