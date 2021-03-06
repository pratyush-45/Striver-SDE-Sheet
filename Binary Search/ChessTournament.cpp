#include<bits/stdc++.h>
bool isPossible(vector<int> positions, int n, int c, int mid){
    int cntNinjasPlaced = 1;
    int lastPlacedNinja = 0;
    for(int i= 1; i< n; i++){
        if(positions[i] - positions[lastPlacedNinja] >= mid){
            cntNinjasPlaced++;
            lastPlacedNinja = i;
        } 
    }
    if(cntNinjasPlaced >= c)
        return true;
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(), positions.end());
    int low = 0;
    int high = positions[n-1] - positions[0];
    int ans = 0;
    
    while(low <= high){
        int mid = (low + high)/ 2;
        
        if(isPossible(positions, n, c, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}