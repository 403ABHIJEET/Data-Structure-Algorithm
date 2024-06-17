#include<iostream>
#include<queue>
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

int sumAtKthLevel(node* root,int k) {
    if(root==NULL)
        return -1;
    int cnt = 0;
    queue<node*> q;
    int ans = 0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* n = q.front();
        q.pop();
        if(n) {
            if(cnt==k)
                ans += n->data;
            if(n->left) 
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty()) {
            q.push(NULL);
            cnt++;
        }
    }
    return ans;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<sumAtKthLevel(root,2)<<endl;
    return 0;
}