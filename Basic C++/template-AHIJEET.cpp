#include<iostream>
using namespace std;

template<typename T1,typename T2>
class ppair {
    public:
    T1 first;
    T2 second;
};

int main() {
    ppair<int,int> p;
    return 0;
}