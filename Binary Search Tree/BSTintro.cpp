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

node* buildBST(node* root,int x) {
    if(!root) 
        return new node(x);
    if(root->data>x) 
        root->left = buildBST(root->left,x);
    else    
        root->right = buildBST(root->right,x);
    return root;
}

void print(node* root) {
    if(!root)
        return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main() {
    int arr[] = {5,1,3,4,2,7};
    node* root = NULL;
    root = buildBST(root,arr[0]);
    for(int i=1; i<sizeof(arr)/sizeof(arr[0]); i++)
        buildBST(root,arr[i]);
    print(root);
    return 0;
}