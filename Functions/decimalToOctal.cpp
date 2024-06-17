#include<iostream>
using namespace std;

int decimalToOctal(int n) {
    int ans = 0;
    int power = 1;
    while(n) {
        ans += n%8*power;
        power *= 10;
        n /= 8;
    }
    return ans;
}

int main() {
    int n; cin>>n;
    cout<<decimalToOctal(n)<<endl;
    return 0;
}