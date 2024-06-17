#include<iostream>
using namespace std;

class node {
    public:
    node* left;
    node* right;
    int data;
    node(int val) {
        left = NULL;                   
        right = NULL;                     
        data = val;
    }
};

void printPreorder(node* root) {
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node* root) {
    if(root==NULL)
        return;
    printPreorder(root->left);
    cout<<root->data<<" ";
    printPreorder(root->right);
}

void printPostorder(node* root) {
    if(root==NULL)
        return;
    printPreorder(root->left);
    printPreorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    printPreorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPostorder(root);
    return 0;
}