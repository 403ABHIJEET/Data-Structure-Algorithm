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

void display(node* head) {
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

node* reverseK(node* &head,int k) {
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr = head->next;
    int cnt = 0;
    while(currptr!=NULL and cnt<k) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        cnt++;
    }
    if(nextptr!=NULL)
        head->next = reverseK(nextptr,k);
    return prevptr;
}

void insertTail(node* &head,int val) {
    if(head==NULL) {
        head = new node(val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = n;
} 

int main() {
    node* head = NULL;
    for(int i=0; i<=10; i++) {
        insertTail(head,i);
    }
    display(head);
    node* head2 = reverseK(head,2);
    display(head2);
    return 0;
}