#include<iostream>
using namespace std;

int main() {
    int n; 
    int m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }
    cout<<endl;
    cout<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) 
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    int a[m][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            a[j][i] = arr[i][j];
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}