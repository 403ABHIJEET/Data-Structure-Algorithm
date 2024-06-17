#include<iostream>
using namespace std;

int main() {
    int n = 89;
    int *ptr = &n;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<n<<endl;
    cout<<&n<<endl;
    return 0;
}