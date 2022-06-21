#include<bits/stdc++.h>
void findSubsets(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &res){
    res.push_back(ds);
    
    for(int i= ind; i< arr.size(); i++){
        if(i != ind && arr[i] == arr[i-1])
            continue;
        ds.push_back(arr[i]);
        findSubsets(i+1, arr, ds, res);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> res;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    findSubsets(0, arr, ds, res);
    return res;
}