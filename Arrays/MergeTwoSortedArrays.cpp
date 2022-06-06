#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
// 	if(n == 0)  return arr1;
//     if(m == 0)  arr1 = arr2;
    
    for(int i= 0; i< m; i++){
        if(arr1[i] > arr2[0]){
            swap(arr1[i], arr2[0]);
            int first = arr2[0];
            
            int k = 1;
            for( ; k < n && arr2[k]< first; k++){
                arr2[k-1] = arr2[k];
            }
            arr2[k-1] = first;
        }
    }
    
    for(int i= 0; i< n; i++){
        arr1[m++] = arr2[i];
    }
    
    return arr1;
}