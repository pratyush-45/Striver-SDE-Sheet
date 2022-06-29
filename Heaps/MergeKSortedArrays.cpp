#include<bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    
    for(int i= 0; i< k; i++){
        for(auto it: kArrays[i]){
            pq.push(it);
        }
    }
    
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    
    return res;
}
