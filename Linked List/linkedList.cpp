#include<iostream>
using namespace std;

class node {
    public:
    node* next;
    int data;
    node(int val) {
        next = NULL;
        data = val;
    }
};

void insertAtHead(node* &head,int val) {
    if(head==NULL) {
        head->data = val;
        return;
    }
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtSpecificPosi(node* &head,int val,int i) {
    if(i==0) {
        insertAtHead(head,val);
        return;
    }   
    node* n = new node(val);
    node* temp = head;
    while(i>1) {
        temp = temp->next;
        i--;
    }
    n->next = temp->next;
    temp->next = n;
}

void insertAtTail(node* &head,int val) {
    if(head==NULL) {
        head->data = val;
        return;
    }
    node* n = new node(val);
    node* temp = head;
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

int main() {
    node* head;
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtHead(head,11);
    insertAtSpecificPosi(head,17,5);
    print(head);
    return 0;
}