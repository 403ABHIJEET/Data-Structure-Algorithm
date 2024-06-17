#include<iostream>
using namespace std;

int main() {
    int n,m,r;
    cin>>n>>m;
    if(m>n) {
        int temp = n;
        n = m;
        m = temp;
    }
    while(r>0) {
        r = n%m;
        n = m;
        m = r;
    }
    cout<<n<<endl;
    return 0;
}