#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int up = 0, down = n-1, left = 0, right = m-1;
    
    // If matrix is in 1D, return as it is
    if(down == 0 or right == 0)return;
    
    while(left < right and up < down) {
        int temp = mat[up][up];
        for(int j = left+1; j<= right; j++){
            swap(temp, mat[up][j]); 
        }
        for(int i= up+1; i<= down; i++){
            swap(temp, mat[i][right]);
        }
        for(int j= right-1; j>= left; j--){
            swap(temp,mat[down][j]);
        }
        for(int i= down-1; i>= up; i--){
            swap(temp,mat[i][left]);
        }

        up++;
        down--;
        left++;
        right--;
    }
}