#include<iostream>
using namespace std;

void subSeq(string s,string ans) {
    if(s.size()==0) {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subSeq(ros,ans);
    subSeq(ros,ans+ch);
}

int main() {
    string s; cin>>s;
    subSeq(s,"");
    return 0;
}