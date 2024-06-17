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

int height(node* root) {
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

int diameter(node* root) {
    if(root==NULL)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDia = lHeight+rHeight+1;
    return max(currDia,max(diameter(root->left),diameter(root->right)));
}

int calcDia(node* root,int* height) {
    if(root==NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int lDia = calcDia(root->left,&lh);
    int rDia = calcDia(root->right,&rh);
    int currDia = lh+rh+1;
    *height = max(lh,rh)+1;
    return max(currDia,max(lDia,rDia));
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int ans = diameter(root);
    int height = 0;
    int ans1 = calcDia(root, &height);
    cout<<ans<<endl;
    cout<<ans1<<endl;
    return 0;
}