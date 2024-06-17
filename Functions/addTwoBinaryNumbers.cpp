#include<iostream>
using namespace std;

string addTwoBinaryNumbers(string n,string m) {
    int i = n.size()-1;
    int j = m.size()-1;
    string ans = "";
    bool carry = false;
    while(i>=0 && j>=0) {
        if(n[i]=='0' && m[j]=='0') {
            if(carry) 
                ans += '1';
            else 
                ans += '0';  
            carry = false;
        }
        else if(n[i]=='1' && m[j]=='1') {
            if(carry) 
                ans += '1';
            else 
                ans += '0';
            carry = true;
        }
        else {
            if(carry) {
                ans += '0';
                carry = true;
            }
            else {
                ans += '1';
                carry = false;
            }
        }
        i--; j--;
    }
    while(i>=0) {
        if(n[i]=='1' && carry) {
            ans += '0';
            carry = true;
        }
        else {
            ans += '1';
            carry = false;
        }
        i--;
    }
    while(j>=0) {
        if(n[j]=='1' && carry) {
            ans += '0';
            carry = true;
        }
        else {
            ans += '1';
            carry = false;
        }
        j--;
    }
    if(carry)
        ans += '1';
    string s = "";
    for(int i=ans.size()-1; i>=0; i--) {
        s += ans[i];
    }
    return s;
}

int main() {
    string n,m;
    cin>>n>>m;
    cout<<addTwoBinaryNumbers(n,m)<<endl;
    return 0;
}