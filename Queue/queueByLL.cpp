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

class queue {
    node* front;
    node* back;
    public:
    queue() {
        front = NULL;
        back = NULL;
    }
    void enqueue(int val) {
        if(front==NULL && back==NULL) {
            front = new node(val);
            back = front;
            return;
        }
        node* n = new node(val);
        back->next = n;
        back = back->next;
    }
    void dequeue() {
        if(front==NULL && back==NULL) {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        node* n = front;
        if(front==back) {
            front = NULL;
            back = NULL;
        }
        else 
            front = front->next;
        delete n;
    }
    int peak() {
        if(front==NULL && back==NULL) {
            cout<<"No element"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty() {
        if(front==NULL && back==NULL)
            return true;
        return false;
    }
};

int main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    while(!q.empty()) {
        cout<<q.peak()<<" ";
        q.dequeue();
    }
    cout<<endl<<q.empty()<<endl;
    return 0;
}