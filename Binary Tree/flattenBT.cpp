#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(node* &root) {
    if(!root || (!root->left && !root->right)) 
        return;
    if(root->left) {
        flatten(root->left);
        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        node* it = root->right;
        while(it->right!=NULL) {
            it = it->right;
        }
        it->right = temp;
    }
    flatten(root->right);
}

void print(node* root) {
    if(!root)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    print(root);
    flatten(root);
    cout<<endl;
    print(root);
    return 0;
}