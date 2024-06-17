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

int maxSum(node* root) {
    if(!root)
        return 0;
    return root->data+max(maxSum(root->left),maxSum(root->right));
}

int main() {
    node* root = new node(1);
    root->left = new node(-12);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(-6);
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right= new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);
    cout<<maxSum(root)<<endl;
    cout<<maxSum(root1)<<endl;
    return 0;
}