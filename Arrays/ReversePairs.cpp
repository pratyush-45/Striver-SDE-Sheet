#include <bits/stdc++.h> 
int merge(vector<int> &arr, int low, int mid, int high){
    int cnt = 0;
    int j = mid + 1;
    for(int i= low; i<= mid; i++){
        while(j <= high && arr[i] > 2*1LL*arr[j]){
            j++;
        }
        cnt += (j - (mid+1));
    }
    
    vector<int> temp;
    int l = low, r = mid + 1;
    while(l <= mid && r <= high){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l++]);
        }
        else{
            temp.push_back(arr[r++]);
        }
    }
    
    while(l <= mid){
        temp.push_back(arr[l++]);
    }
    while(r <= high){
        temp.push_back(arr[r++]);
    }
    
    for(int i= low; i<= high; i++){
        arr[i] = temp[i - low];
    }
    
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    if(low >= high)
        return 0;
    
    int mid = (low + high)/ 2;
    int inv = 0;
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid+1, high);
    
    inv += merge(arr, low, mid, high);
    
    return inv;
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr, 0, arr.size()-1);
}