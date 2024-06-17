#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    int n; cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin>>mat[i][j];
    }
    vector<vector<int>> curr = mat;
    int currH = INT_MAX;
    while(1) {
        int h = heuristic(curr);
        if(h < currH) {
            
        }
    }
    return 0;
}