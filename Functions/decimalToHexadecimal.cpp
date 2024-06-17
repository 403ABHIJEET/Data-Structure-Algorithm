#include<iostream>
using namespace std;

string decimalToHexadecimal(int n) {
    string s = "";
    string temp = "";
    while(n) {
        int remain = n%16;
        if(remain>=0 && remain<=9)
            temp += remain+'0';
        else 
            temp += 'A'+remain-10;
        n /= 16;
    }
    for(int i=temp.size()-1; i>=0; i--)
        s += temp[i];
    return s;
}

int main() {
    int n; cin>>n;
    cout<<decimalToHexadecimal(n);
    return 0;
}