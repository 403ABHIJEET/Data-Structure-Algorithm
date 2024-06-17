#include<iostream>
#include<stack>
using namespace std;

void reverse(string s) {
    stack<string> st;
    for(int i=0; i<s.size(); i++) {
        string w = "";
        while(s[i]!=' ' && i<s.size()) {
            w += s[i];
            i++;
        }
        st.push(w);
    }
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main() {
    string s = "hey how you doin' well i'am doin' just fine i lie i'm dyin' inside";
    reverse(s);
    return 0;
}