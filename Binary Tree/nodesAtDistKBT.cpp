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

void printSubTreeNode(node* root,int k) {
    if(!root || k<0) 
        return;
    if(k==0) {
        cout<<root->data<<" ";
        return;
    }
    printSubTreeNode(root->left,k-1);
    printSubTreeNode(root->right,k-1);
}

int printNodesAtK(node* root,node* target,int k) {
    if(!root)
        return -1;
    if(root==target) {
        printSubTreeNode(root,k);
        return 0;
    }
    int dl = printNodesAtK(root->left,target,k);
    if(dl!=-1) {
        if(dl+1==k)
            cout<<root->data<<" ";
        else    
            printSubTreeNode(root->right,k-dl-2);
        return 1+dl; 
    }
    int dr = printNodesAtK(root->right,target,k);
    if(dr!=-1) {
        if(dr+1==k)
            cout<<root->data<<" ";
        else    
            printSubTreeNode(root->left,k-dr-2);
        return 1+dr; 
    }
    return -1;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right->left->left = new node(12);
    root->right->left->right = new node(13);
    root->right->right->left = new node(14);
    root->right->right->right = new node(15);
    printNodesAtK(root,root->right->right,3);
    return 0;
}