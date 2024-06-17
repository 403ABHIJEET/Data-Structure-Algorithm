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

int length(node* head) {
    int l = 0;
    while(head!=NULL) {
        l++;
        head = head->next;
    }
    return l;
}

int findIntersection(node* head1,node* head2) {
    int l1 = length(head1);
    int l2 = length(head2);
    node* temp1;
    node* temp2;
    int k;
    if(l1>l2) {
        k = l1-l2;
        temp1 = head1;
        temp2 = head2;
    }
    else {
        k = l2-l1;
        temp1 = head2;
        temp2 = head1;
    }
    while(k) {
        temp1 = temp1->next;
        k--;
    }
    while(temp1!=NULL and temp2!=NULL) {
        if(temp1==temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

int main() {
    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);
    head1->next->next->next->next = new node(5);
    head1->next->next->next->next->next = new node(6);
    node* head2 = new node(9);
    head2->next = new node(10);
    head2->next->next = head1->next->next->next->next;
    print(head1);
    print(head2);
    cout<<findIntersection(head1,head2)<<endl;
    return 0;
}