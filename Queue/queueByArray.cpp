#include<iostream>
using namespace std;

class queue {
    int front;
    int back;
    int n;
    int arr[];
    public:
    queue(int val) {
        front = -1;
        back = -1;
        n = val;
        arr[n];
    }
    void enqueue(int val) {
        if(back==n-1) {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        arr[++back] = val;
        if(front==-1)
            front++;
    }
    void dequeue() {
        if(front==-1 || front>back) {
            cout<<"Queue Undeflow"<<endl;
            return;
        } 
        front++;
    }
    int peak() {
        if(front==-1 || front>back) {
            cout<<"No element"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty() {
        if(front==-1 || front>back)
            return true;
        return false;
    }
};

int main() {
    queue q = queue(100);
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