#include<iostream>
using namespace std;

int main() {
    int a,b,n;
    cin>>a>>b>>n;
    int cntA = 0;
    int cntB = 0;
    int cntAB = 0;
    for(int i=0; i<n; i++) {
        if((i+1)%a==0)
            cntA++;
        if((i+1)%b==0)
            cntB++;
        if((i+1)%(a*b)==0)
            cntAB++;
    }
    cout<<(cntA+cntB-cntAB)<<endl;
    return 0;
}