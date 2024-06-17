#include<iostream>
#include<stack>
using namespace std;

int redundant(string s) {
    int ans = 0;
    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            st.push(s[i]);
        else if(s[i]==')') {
            if(st.top()=='(')
                ans++;
            else {
                while(st.top()!='(') {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return ans;
}

int main() {
    string s = "((a+b))";
    string s2 = "(a-(a+b))";
    int n1 = redundant(s);
    int n2 = redundant(s2);
    cout<<n1<<" "<<n2<<endl;
    return 0;
}