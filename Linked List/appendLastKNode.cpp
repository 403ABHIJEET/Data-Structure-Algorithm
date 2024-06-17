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

void insert(node* &head,int x) {
    if(head==NULL) {
        head = new node(x);
        return;
    }
    node* temp = head;
    node* n = new node(x);
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void print(node* head) {
    if(head==NULL) {
        cout<<"NULL"<<endl;
        return;
    }
    while(head!=NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

node* appendK(node* &head,int k) {
    if(head==NULL)
        return NULL;
    node* tail = head;
    node* newhead;
    node* newTail;
    int cnt = 1;
    while(tail->next!=NULL) {
        if(cnt==k) 
            newTail = tail;
        if(cnt==k+1)
            newhead = tail;
        tail = tail->next;
        cnt++;
    }
    tail->next = head;
    newTail->next = NULL;
    return newhead;
}

int main() {
    node* head = NULL;
    for(int i=0; i<8; i++)
        insert(head,i);
    print(head);
    node* head2 = appendK(head,3);
    print(head2);
    return 0;
}