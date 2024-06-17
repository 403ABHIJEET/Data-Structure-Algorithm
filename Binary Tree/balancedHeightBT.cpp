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
    if(!root)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

bool balanced(node* root) {
    if(!root)
        return true;
    if(!balanced(root->left))
        return false;
    if(!balanced(root->right))
        return false;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)>=1)
        return false;
    return true;
}   

bool isBalanced(node* root,int* height) {
    if(!root)
        return true;
    int lh = 0;
    int rh = 0;
    if(!isBalanced(root->left,&lh))
        return false;
    if(!isBalanced(root->right,&rh))
        return false;
    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1)
        return true;
    return false;
}

int main() {
    node* root = new node(1);                 
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    bool flag = balanced(root);
    int height = 0;
    bool flag2 = isBalanced(root,&height);
    if(flag)
        cout<<"Balanced"<<endl;
    else    
        cout<<"Not Balanced"<<endl;
    if(flag2)
        cout<<"Balanced"<<endl;
    else    
        cout<<"Not Balanced"<<endl;
    return 0;
}