#include<iostream>
#include<queue>
using namespace std;

class stack {
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack() {
        N = 0;
    }
    void push(int x) {
        q1.push(x);
        N++;
    }
    void pop() {
        if(q1.empty())
            return;
        while(q1.size()!=1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top() {
        if(q1.empty())
            return -1;
        while(q1.size()!=1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topval = q1.front();
        q2.push(topval);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return topval;
    }
    int size() {
        return N;
    }
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};

int main() {
    stack s = stack();
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}