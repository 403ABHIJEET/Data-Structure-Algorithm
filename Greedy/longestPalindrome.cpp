#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(),s.end());
        cout<<s<<endl;
        int count = 1;
        int ans = 0;
        for(int i=0; i<s.size()-1; i++) {
            if(s[i]==s[i+1]) {
                count++;
                cout<<count<<endl;
            }
            else {
                ans += 2*(count/2);   // abccccdd
                count = 1;        // aadm
            }
        }
        ans += 2*(count/2);
        if(ans<s.size()) 
            return 1+ans;
        return ans;
    } 
};

int main() {
    string s; cin>>s;
    Solution s1;
    cout<<s1.longestPalindrome(s)<<endl;
    return 0;
}