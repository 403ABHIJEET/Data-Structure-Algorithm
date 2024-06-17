#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            st.push(s[i]);
        else {
            if(!st.empty() && s[i]=='}' && st.top()=='{') {
                st.pop();
            }
            else if(!st.empty() && s[i]==']' && st.top()=='[') {
                st.pop();
            }
            else if(!st.empty() && s[i]==')' && st.top()=='(') {
                st.pop();
            }
            else 
                return false;
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main() {
    string s = "{[()]}";
    string s2 = "[()]}";
    cout<<isBalanced(s)<<" "<<isBalanced(s2)<<endl;
    return 0;
}