#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan(vector<int> prices) {
    vector<int> ans;
    stack<pair<int,int>> sp;
    for(int i=0; i<prices.size(); i++) {
        int span = 1;
        while(!sp.empty() && sp.top().first<=prices[i]) {
            span += sp.top().second;
            sp.pop();
        }
        sp.push({prices[i],span});
        ans.push_back(span);
    }
    return ans;
}

int main() {
    vector<int> v = {100,80,60,70,60,75,85};
    vector<int> ans = stockSpan(v);
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}