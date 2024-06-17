#include<iostream>
#include<queue>
#include<vector>
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

node* LCA(node* root,int n1,int n2) {
    if(!root)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    node* left = LCA(root->left,n1,n2);
    node* right = LCA(root->right,n1,n2);
    if(left && right)
        return root;
    if(!left && !right)
        return NULL;
    if(left)
        return LCA(root->left,n1,n2);
    return LCA(root->right,n1,n2);
} 

int findDist(node* root,int n,int d) {
    if(!root)
        return -1;
    if(root->data==n)
        return d;
    int left = findDist(root->left,n,d+1);
    if(left!=-1)
        return left;
    return findDist(root->right,n,d+1);
}

int shortestDist(node* root,int n1,int n2) {
    node* lca = LCA(root,n1,n2);
    int d1 = findDist(root,n1,0);
    int d2 = findDist(root,n2,0);
    return d1+d2;
}

int shortestDist(node* root) {
    
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int ans = shortestDist(root,5,7);
    cout<<ans<<endl;
    return 0;
}