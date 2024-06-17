#include<iostream>
#include<bits/stdc++.h>
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

int search(int inorder[],int start,int end,int curr) {
    for(int i=start; i<=end; i++) {
        if(inorder[i]==curr)
            return i;
    }
    return -1;
}

node* buildTree(int preorder[],int inorder[],int start,int end) {
    static int idx = 0;
    if(start>end)
        return NULL;
    int curr = preorder[idx];
    idx++;
    node* n = new node(curr);
    if(start==end)
        return n;
    int pos = search(inorder,start,end,curr);
    n->left = buildTree(preorder,inorder,start,pos-1);
    n->right = buildTree(preorder,inorder,pos+1,end);
    return n;
}

void printInorder(node* root) {
    if(root==NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int n = 5;
    node* root = buildTree(preorder,inorder,0,n-1);
    printInorder(root);
    cout<<endl;
    return 0;
}