#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            if(i%2==0 && j%2==0)
                cout<<1;
            else if(i%2!=0 && j%2!=0)
                cout<<1;
            else    
                cout<<0;
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}