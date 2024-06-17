#include <bits/stdc++.h> 
using namespace std;

double maximumValue(vector<pair<int, int>>& items, int n, int w) {
    vector<pair<double,int>> ratio;
    for(int i=0; i<n; i++) {
        double w1 = items[i].first;
        
        double v = items[i].second;
        double r = v/w1;
        cout<<v<<" ";
        ratio.push_back({r,i});
    }
    cout<<endl;
    sort(ratio.begin(),ratio.end());
    double ans = 0;
    int i = 0;
    while(w) {
        if(w>items[ratio[i].second].first) {
            w -= items[ratio[i].second].first;
            ans += items[ratio[i].second].second;
        }
        else {
            double temp = w;
            ans += temp*ratio[i].first;
            break;
        }
        i++;
    } 
    return ans;
}

int main() {
    int t; cin>>t;
    for(int i=0; i<t; i++) {
        int n,w; cin>>n>>w;
        vector<pair<int,int>> v(n);
        for(int j=0; j<n; j++) 
            cin>>v[i].first;
        for(int j=0; j<n; j++) 
            cin>>v[i].second;
        cout<<maximumValue(v,n,w)<<endl;
    }
    return 0;
}