#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool minus = false;
        bool plus = false;
        string st = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='-') {
                if(plus)
                    break;
                minus = true;
            }
            else if(s[i]=='+') {
                if(minus)
                    break;
                plus = true;
            }
            else if(s[i]>='0' && s[i]<='9')
                st += s[i];
            else if(s[i]==' ')
                continue;
            else
                break;
        }
        long ans = 0;
        for(int i=0; i<st.size(); i++) {
            ans *= 10;
            ans += st[i]-'0';
        }
        if(minus) {
            if(ans>=2147483648)
                return 2147483648;
            return (int)ans*(-1);
        }
        if(ans>=2147483647)
            return 2147483647;
        return (int)ans;
    }
};

int main() {
    string s; cin>>s;
    Solution s1;
    cout<<s1.myAtoi(s)<<endl;
}