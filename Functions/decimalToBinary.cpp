#include<iostream>
using namespace std;

string decimalToBinary(int n) {
    string ans = "";
    string temp = "";
    while(n) {
        temp += '0'+n%2;
        n /= 2;
    }
    for(int i=temp.size()-1; i>=0; i--) 
        ans += temp[i];
    return ans;
}

int main() {
    int n; cin>>n;
    cout<<decimalToBinary(n)<<endl;
    return 0;
}