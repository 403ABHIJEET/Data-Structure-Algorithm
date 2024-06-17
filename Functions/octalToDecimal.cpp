#include<iostream>
using namespace std;

int octalToDecimal(int n) {
    int power = 1;
    int ans = 0;
    while(n) {
        ans += power*(n%10);
        power *= 8;
        n /= 10;
    }
    return ans;
}

int main() {
    int n; cin>>n;
    cout<<octalToDecimal(n)<<endl;
    return 0;
}