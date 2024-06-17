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

vector<int> rightView(node* root) {
    if(root==NULL)
        return {};
    queue<node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; i++) {
            node* curr = q.front();
            q.pop();
            if(i==0)
                ans.push_back(curr->data);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
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
    vector<int> ans = rightView(root);
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}