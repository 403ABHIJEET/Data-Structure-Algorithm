#include<iostream>
using namespace std;

int main() {
    string s; cin>>s;
    string lower = "";
    string upper = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='A' && s[i]<='Z') {
            upper += s[i];
            lower += s[i]-'A'+'a';
        }
        else {
            upper += s[i]-'a'+'A';
            lower += s[i];
        }
    }
    cout<<upper<<endl;
    cout<<lower<<endl;
    return 0;
}