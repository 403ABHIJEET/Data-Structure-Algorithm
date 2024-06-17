#include<iostream>
#include<set>
#include<limits.h>
#include<vector>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> ans;
    multiset<int,greater<int>> s;
    for(int i=0; i<k; i++)  
        s.insert(arr[i]);
    ans.push_back(*s.begin());
    for(int i=k; i<n; i++) {
        s.erase(s.lower_bound(arr[i-k]));
        s.insert(arr[i]);
        ans.push_back(*s.begin());
    }
    for(auto i : ans)   
        cout<<i<<" ";
    cout<<endl;
}