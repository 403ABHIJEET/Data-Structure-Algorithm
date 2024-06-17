#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &st,int l) {
    if(st.empty()) {
        st.push(l);
        return;
    }
    int tl = st.top();
    st.pop();
    insertBottom(st,l);
    st.push(tl);
}

void reverse(stack<int> &st) {
    if(st.empty())
        return;
    int l = st.top();
    st.pop();
    reverse(st);
    insertBottom(st,l);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while(!st.empty()) {
        cout<<st.top()<<endl;
        st.pop();
    }    
    return 0;
}