#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<string> board,int row,int col) {
        for(int i=row-1; i>=0; i--) {
            if(board[i][col]=='Q')
                return false;
        }
        int i = row-1;
        int j = col-1;
        while(i>=0 && col>=0) {
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i = row-1;
        j = col+1;
        while(i>=0 && col<board.size()) {
            if(board[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    vector<vector<string>> ans;
    void nQueen(vector<string> board,int idx) {
        if(idx==board.size()) {
            ans.push_back(board);
            return;
        }
        for(int i=0; i<board.size(); i++) {
            if(isSafe(board,idx,i)) {
                board[idx][i] = 'Q';
                nQueen(board,idx+1);
                board[idx][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s = "";
        for(int i=0; i<n; i++)
            s += '.';
        for(int i=0; i<n; i++)
            board.push_back(s);
        nQueen(board,0);
        return ans;
    }
};

int main() {
    int n; cin>>n;
    Solution s1;
    vector<vector<string>> ans = s1.solveNQueens(n);
    for(auto i : ans) {
        for(auto j : i)
            cout<<j<<endl;
        cout<<endl;
    } 
    return 0;
}