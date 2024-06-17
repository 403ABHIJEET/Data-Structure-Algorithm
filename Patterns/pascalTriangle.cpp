#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascal(int n) {
    if(n==1) 
        return {{1}};
    else if(n==2) 
        return {{1,1}};
    vector<vector<int>> ans;
    ans.push_back({1});
    ans.push_back({1,1});
    for(int i=1; i<n-1; i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j=0; j<ans[i].size()-1; j++) {
            temp.push_back(ans[i][j]+ans[i][j+1]);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    int n; cin>>n;
    vector<vector<int>> v = pascal(n);
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<n-i; j++)
            cout<<" ";
        for(int j=0; j<v[i].size(); j++)    
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}