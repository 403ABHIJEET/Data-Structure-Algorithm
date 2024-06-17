#include<iostream>
#include<stack>
using namespace std;

int solve(string s) {
    stack<int> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');
        else {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            switch(s[i]) {
                case '+' :
                    st.push(n1+n2);
                    break;
                case '-' :
                    st.push(n2-n1);
                    break;
                case '*' :
                    st.push(n1*n2);
                    break;
                case '/' :
                    st.push(n2/n1);
                    break;
            }
        }
    }
    return st.top();
}

int main() {
    string s = "46+2/5*7+";
    int ans = solve(s);
    cout<<ans<<endl;
    return 0;
}