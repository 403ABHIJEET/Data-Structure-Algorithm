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

int search(int inorder[],int s,int e,int curr) {
    for(int i=s; i<=e; i++) {
        if(inorder[i]==curr)
            return i;
    }
    return -1;
}

node* buildTree(int postorder[],int inorder[],int s,int e) {
    static int idx = 4;
    if(s>e) 
        return NULL;
    int curr = postorder[idx];
    idx--;
    node* n = new node(curr);
    if(s==e)
        return n;
    int pos = search(inorder,s,e,curr);
    n->right = buildTree(postorder,inorder,pos+1,e);
    n->left = buildTree(postorder,inorder,s,pos-1);
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
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    int n = 5;
    node* root = buildTree(postorder,inorder,0,n-1);
    printInorder(root);
    cout<<endl;
    return 0;
}