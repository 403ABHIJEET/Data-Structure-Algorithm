#include<iostream>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    int x; cin>>x;
    int arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    int r = 0;
    int c = m-1;
    bool flag = false;
    while(r<n && c>=0) {
        if(arr[r][c]==x) {
            flag = true;
            break;
        }
        else if(arr[r][c]<x) 
            r++;
        else 
            c--;
    }
    if(flag) 
        cout<<"True"<<endl;
    else    
        cout<<"False"<<endl;
    return 0;
}