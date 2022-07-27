#include<bits/stdc++.h>

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> res;
    unordered_map<int, int> m;
    
    for(int i= 0; i< k; i++){
        m[arr[i]]++;
    }
    res.push_back(m.size());
    
    for(int i= k; i< arr.size(); i++){
        m[arr[i-k]]--;
        if(m[arr[i-k]] == 0)
            m.erase(arr[i-k]);
        
        m[arr[i]]++;
        res.push_back(m.size());
    }
    
    return res;
}
