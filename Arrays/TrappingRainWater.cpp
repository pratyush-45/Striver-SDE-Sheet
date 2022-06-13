#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    int left = 0, right = n-1;
    long res = 0;
   long maxLeft = 0, maxRight = 0;
    
    while(left <= right){
        maxLeft = max(maxLeft, arr[left]);
        maxRight = max(maxRight, arr[right]);
        
        if(maxLeft < maxRight){
            res += maxLeft - arr[left];
            left++;
        }
        else{
            res += maxRight - arr[right];
            right--;
        }
    }
    return res;
}