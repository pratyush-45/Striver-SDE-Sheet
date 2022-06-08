#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int lo = 0;
    int hi = (m*n) - 1;
    
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(mat[mid/n][mid%n] == target)
            return true;
        else if(mat[mid/n][mid%n] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    
    return false;
}