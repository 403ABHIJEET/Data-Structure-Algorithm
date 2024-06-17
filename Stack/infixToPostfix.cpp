#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverse(string &s) {
    string temp = "";
    for(int i=0; i<s.size(); i++)
        temp += s[i];
    for(int i=s.size()-1; i>=0; i--)
        s[s.size()-i-1] = temp[i];
}

int prec(char s) {
    if(s=='^')
        return 3;
    else if(s=='*' || s=='/')
        return 2;
    else if(s=='+' || s=='-')
        return 1;
    return -1;
}

string infixToPostfix(string s) {
    reverse(s);
    string ans = "";
    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a' && s[i]<='z')
            ans += s[i];
        else if(s[i]==')')
            st.push(s[i]);
        else if(s[i]=='(') {
            while(!st.empty() && st.top()!=')') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else {
            while(!st.empty() && prec(st.top())>=prec(s[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans);
    return ans;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    string ans = infixToPostfix(s);
    cout<<ans<<endl;
    return 0;
}