#include<iostream>
using namespace std;

int getBit(int n,int pos) {
    return (n & 1<<pos)!=0;
}

int setBit(int n,int pos) {
    return (n | (1<<pos));
}

int clearBit(int n,int pos) {
    int mask = ~(1<<pos);
    return (mask & n);
}

int updateBit(int n,int pos,int val) {
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | val<<pos);
}

int main() {
    int n = 5;
    cout<<getBit(n,2)<<endl;
    cout<<setBit(n,1)<<endl;
    cout<<clearBit(n,2)<<endl;
    cout<<updateBit(n,1,1)<<endl;
    return 0;
}