#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    vector<int> res;
    
    for(auto it: arr){
        maxHeap.push(it);
        minHeap.push(it);
        
        if(maxHeap.size() > k)
            maxHeap.pop();
        if(minHeap.size() > k)
            minHeap.pop();
    }
    
    res.push_back(maxHeap.top());
    res.push_back(minHeap.top());
    return res;
}