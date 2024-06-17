#include<iostream>
using namespace std;

int binaryToDecimal(string s) {
    int ans = 0;
    int power = 1;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i]=='1') {
            ans += power;
        }
        power *= 2;
    }
    return ans;
}

int main() {
    string s; cin>>s;
    int ans = binaryToDecimal(s);
    cout<<ans<<endl;
    return 0;
}