#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left  = NULL;
        right = NULL;
    }
};

bool searchNode(node* root,int x) {
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    if(root->data>x)
        return searchNode(root->left,x);
    return searchNode(root->right,x);
}

node* inorderSucc(node* root) {
    node* curr = root;
    while(curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

node* deleteNode(node* root,int x) {
    if(root->data>x)
        root->left = deleteNode(root->left,x); 
    else if(root->data<x)
        root->right = deleteNode(root->right,x);
    else {
        if(!root->left) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

int main() {
    node* root = NULL;
    if(searchNode(root,5))
        cout<<"Key does exist"<<endl;
    else    
        cout<<"key doesn't exist"<<endl;
    return 0;
}