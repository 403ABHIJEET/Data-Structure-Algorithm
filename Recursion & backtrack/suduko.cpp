#include<bits/stdc++.h>
using namespace std;

bool help(int r,int c,vector<vector<char>> &suduko,map<pair<int,int>,map<int,int>> &mp,vector<map<int,int>> &row,vector<map<int,int>> &col) {
    if(r==9)
        return true;
    if(c==9) {
        if(help(r+1,0,suduko,mp,row,col))
            return true;
        return false;
    }
    for(int i=1; i<=9; i++) {
        int rw = r/3;
        int cl = c/3;
        if(!mp[{rw,cl}][i] and !row[r][i] and !col[c][i]) {
            mp[{rw,cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            suduko[r][c] = i+'0';
            if(help(r,c+1,suduko,mp,row,col))
                return true;
            suduko[r][c] = '.';
            mp[{rw,cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
        }
    }
    return false;
}

vector<vector<char>> solveSuduko(vector<vector<char>> &suduko) {
    map<pair<int,int>,map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);
    for(int i=0; i<suduko.size(); i++) {
        for(int j=0; j<suduko[i].size(); j++) {
            if(suduko[i][j]!='.') {
                mp[{i/3,j/3}][suduko[i][j]-'0'] = 1;
                row[i][suduko[i][j]] = 1;
                col[j][suduko[i][j]] = 1;
            }
        }
    }
    if(help(0,0,suduko,mp,row,col))
        return suduko;
    return suduko;
}

int main() {
    vector<vector<char>> suduko = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> ans = solveSuduko(suduko);
    for(auto i : ans) {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}