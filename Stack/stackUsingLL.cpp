#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    } 
};

class stack {
    node* top;
    public:
    stack() {
        top = NULL;
    }
    void push(int val) {
        if(top==NULL) {
            top = new node(val);
            return;
        }
        node* n = new node(val);
        n->next = top;
        top = n;
    }
    void pop() {
        if(top==NULL) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        node* n = top;
        top = top->next;
        delete n;
    }
    int peak() {
        if(top==NULL) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
    bool empty() {
        if(top==NULL)
            return true;
        return false;
    }
    int size() {
        if(top==NULL)
            return 0;
        node* temp = top;
        int cnt = 0;
        while(temp!=NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};

int main() {
    stack s = stack();
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