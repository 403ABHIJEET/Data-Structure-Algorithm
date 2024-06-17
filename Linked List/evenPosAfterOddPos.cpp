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

void addList(node* &head,int x) {
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

void evenAfterOdd(node* &head) {
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return;
    node* odd = head;
    node* startEven = head->next;
    node* even = startEven;
    while(odd->next!=NULL && even->next!=NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = startEven;
    if(odd->next==NULL) 
        even->next = NULL;
}

int main() {
    node* head1 = NULL;
    for(int i=1; i<9; i++)
        addList(head1,i);
    display(head1);
    evenAfterOdd(head1);
    display(head1);
    cout<<endl;
    node* head2 = NULL;
    for(int i=1; i<8; i++)
        addList(head2,i);
    display(head2);
    evenAfterOdd(head2);
    display(head2);
    return 0;
}