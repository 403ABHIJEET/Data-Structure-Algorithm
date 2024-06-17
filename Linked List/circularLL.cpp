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

void makeCircular(node* &head,int x) {
    if(head==NULL) {
        head = new node(x);
        head->next = head;
        return;
    }
    node* temp = head;
    node* n = new node(x);
    while(temp->next!=head) {
        temp = temp->next;
    }
    temp->next = n;
    temp->next->next = head;
}

void display(node* head) {
    if(head==NULL) {
        cout<<"NULL"<<endl;
        return;
    }
    node* temp = head;
    do {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    while(temp!=head);
    cout<<endl;
}

int main() {
    node* head = NULL;
    for(int i=0; i<8; i++)
        makeCircular(head,i);
    display(head);
    return 0;
}