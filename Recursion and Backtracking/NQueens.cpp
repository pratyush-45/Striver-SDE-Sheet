#include<bits/stdc++.h>
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &res, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col == n){
        vector<int> temp;
        for(auto it: board){
            for(auto it2: it){
                temp.push_back(it2);
            }
        }
        res.push_back(temp);
        return;
    }
    
    for(int row= 0; row< n; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
            board[row][col] = 1;
            //Hashing
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            //
            solve(col+1, board, res, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = 0;
            //De-hashing
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> res;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
    
    solve(0, board, res, leftRow, upperDiagonal, lowerDiagonal, n);
    return res;
}