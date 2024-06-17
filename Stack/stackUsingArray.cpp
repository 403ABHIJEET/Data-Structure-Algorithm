#include<iostream>
using namespace std;

class stack {
    int top;
    int* arr;
    int n;
    public:
    stack(int val) {
        top = -1;
        arr = new int[val];
        n = val;
    }
    void push(int val) {
        if(top==n-1) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = val;
    }
    void pop() {
        if(top==-1) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int peak() {
        if(top==-1) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty() {
        if(top==-1)
            return true;
        return false;
    }
    int size() {
        return top+1;
    }
};

int main() {
    stack s = stack(300);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peak()<<endl;
    s.pop();
    cout<<s.peak()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}