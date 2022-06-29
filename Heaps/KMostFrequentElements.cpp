#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{    
    unordered_map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> res;
    
    for(auto it: arr){
        m[it]++;
    }
    
    for(auto it: m){
        minHeap.push({it.second, it.first});
        
        if(minHeap.size() > k)
            minHeap.pop();
    }
    
    while(!minHeap.empty()){
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    sort(res.begin(), res.end());
    
    return res;
}