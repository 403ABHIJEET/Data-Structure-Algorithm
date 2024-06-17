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

void makeCycle(node* &head,int k) {
    if(head==NULL)
        return;
    node* temp = head;
    node* start;
    int cnt = 1;
    while(temp->next!=NULL) {
        if(cnt==k) 
            start = temp;
        temp = temp->next;
        cnt++;
    }
    temp->next = start;
}

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

void removeCycle(node* &head) {
    if(head==NULL)
        return;
    node* fast = head;
    node* slow = head;
    while(fast!=NULL and fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
            break;
    }
    fast = head;
    while(fast->next!=slow->next) {
        fast =  fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int main() {
    node* head = NULL;
    for(int i=0; i<12; i++) 
        insert(head,i);
    makeCycle(head,4);
    removeCycle(head);
    display(head);
    return 0;
}