#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node* prev;
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(node* &head,int val) {
    if(head==NULL) {
        head = new node(val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL) 
        temp = temp->next;
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
    node* head = NULL;
    int n; cin>>n;
    for(int i=0; i<n; i++) 
        insertAtTail(head,i);
    print(head);
    return 0;
}