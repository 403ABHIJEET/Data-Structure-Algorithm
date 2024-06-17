#include<iostream>
using namespace std;

string moveXtoEnd(string s) {
    if(s.size()==0) {
        return "";
    }
    char ch = s[0];
    string ans = moveXtoEnd(s.substr(1));
    if(ch=='x')
        return ans+ch;
    return ch+ans;
}

int main() {
    string s; cin>>s;
    cout<<moveXtoEnd(s)<<endl;
    return 0;
}