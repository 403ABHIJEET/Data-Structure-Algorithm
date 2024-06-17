#include<iostream>
using namespace std;

int main() {
    int p,q,r;
    cin>>p>>q>>r;
    int a[p][q],b[q][r];
    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) 
            cin>>a[i][j];
    }
    for(int i=0; i<q; i++) {
        for(int j=0; j<r; j++)
            cin>>b[i][j];
    }
    cout<<"Matrix1:"<<endl<<endl;
    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) 
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix2:"<<endl;
    cout<<endl;
    for(int i=0; i<q; i++) {
        for(int j=0; j<r; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix1 X Matrix2 = Matrix3:"<<endl;
    int c[p][r];
    for(int i=0; i<p; i++) {
        for(int j=0; j<r; j++) 
            c[i][j] = 0;
    }
    for(int i=0; i<p; i++) {
        for(int j=0; j<r; j++) {
            for(int k=0; k<q; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0; i<p; i++) {
        for(int j=0; j<r; j++) 
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
