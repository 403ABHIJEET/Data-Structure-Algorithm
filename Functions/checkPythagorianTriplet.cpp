#include<bits/stdc++.h>
using namespace std;

bool isPythagorian(int a,int b,int c) {
    int x = b*b+c*c;
    int y = a*a+c*c;
    int z = b*b+a*a;
    if(x==a*a || y==b*b || z==c*c)
        return true;
    return false;
}

int main() {
    int a,b,c;
    isPythagorian(a,b,c);
    if(isPythagorian)
        cout<<"Yes"<<endl;
    else    
        cout<<"No"<<endl;
    return 0;
}