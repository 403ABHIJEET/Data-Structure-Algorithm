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

node* reverse(node* &head) {
    node* prev = NULL;
    node* curr = head;
    node* nextptr = head->next;
    while(curr!=NULL) {
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    } 
    return prev;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    display(head);
    node* head1 = reverse(head);
    display(head1);
    return 0;
}