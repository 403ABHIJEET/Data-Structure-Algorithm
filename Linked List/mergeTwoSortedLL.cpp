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

node* merge(node* head1,node* head2) {
    node* head3 = NULL;
    while(head1!=NULL && head2!=NULL) {
        if((head1->data)<(head2->data)) {
            insert(head3,head1->data);
            head1 = head1->next;
        }
        else {
            insert(head3,head2->data);
            head2 = head2->next;
        }
    }
    while(head1!=NULL) {
        insert(head3,head1->data);
        head1 = head1->next;
    }
    while(head2!=NULL) {
        insert(head3,head2->data);
        head2 = head2->next;
    }
    return head3;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    for(int i=1; i<23; i++) {
        if(i%2==0)
            insert(head1,i);
        else
            insert(head2,i);
    }
    print(head1);
    print(head2);
    node* head3 = merge(head1,head2);
    print(head3);
    return 0;
}