#include<bits/stdc++.h>
bool isvalid(int matrix[9][9], int row, int col, int val){
    for(int i= 0; i< 9; i++)
    {
        if(matrix[row][i] ==  val) 
            return false;
        if(matrix[i][col] == val) 
            return false;
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3] == val) 
            return false;
    }
    return true;
}

bool solve(int matrix[9][9]){
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++){
           if(matrix[i][j] == 0){
                for(int c= 1; c<= 9; c++){
                    if(isvalid(matrix, i, j, c)){
                        matrix[i][j] = c;
                        
                        if(solve(matrix) == true)
                            return true;
                        else
                         matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    return solve(matrix);
}
