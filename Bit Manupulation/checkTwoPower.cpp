#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    if((n & (n-1)) == 0)
        cout<<"It is"<<endl;
    else    
        cout<<"Absolutely not"<<endl;
    return 0;
}