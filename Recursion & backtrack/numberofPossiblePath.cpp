#include<iostream>
using namespace std;

int countPath(int s,int e,int p) {
    if(s==e) 
        return 1;
    if(s>e) 
        return 0;
    int count = 0;;
    for(int i=1; i<=p; i++) 
        count += countPath(s+i,e,p);
    return count;
}

int main() {
    int n,p;
    cin>>n>>p;
    cout<<countPath(0,n,p);
    return 0;
}