#include<iostream>
#include<limits.h>
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

node* buildBST(int arr[],int n,int* preOrder,int min,int max) {
    
}

void preorder(node* root) {
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int* preOrder = 0;
    node* root = buildBST(arr,n,preOrder,INT_MIN,INT_MAX);
    preorder(root);
    return 0;
}