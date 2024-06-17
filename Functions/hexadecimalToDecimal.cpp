#include<iostream>
using namespace std;

int hexadecimalToDecimal(string s) {
    int ans = 0;
    int power = 1;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i]>='0' && s[i]<='9') 
            ans += power*(s[i]-'0');
        else 
            ans += power*(s[i]-'A'+10);
        power *= 16;
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<hexadecimalToDecimal(s)<<endl;
    return 0;
}