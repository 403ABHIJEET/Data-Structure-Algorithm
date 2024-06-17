#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = 0;
    stack<int> s;
    for(int i=0; i<v.size(); i++) {
        while(!s.empty() && v[s.top()]<v[i]) {
            int curr = s.top();
            s.pop();
            if(s.empty())
                break;
            int diff = i-s.top()-1;
            ans += (min(v[s.top()],v[i])-v[curr])*diff;
        }
        s.push(i);
    }
    cout<<ans<<endl;
    return 0;
}