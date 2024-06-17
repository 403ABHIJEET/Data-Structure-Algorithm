#include<iostream>
using namespace std;

int solve(string s) {
    int flag[26];
    int ans = 0;
    int start = -1;
    for(int i=0; i<26; i++) {
        flag[i] = -1;
    }
    for(int i=0; i<s.size(); i++) {
        if(flag[s[i]-'a']>start)
            start = flag[s[i]-'a'];
        flag[s[i]-'a'] = i;
        ans = max(ans,i-start);
    }
    return ans;
}

int main() {
    string s = "pwwwew";
    int ans = solve(s);
    cout<<ans<<endl;
    return 0;
}