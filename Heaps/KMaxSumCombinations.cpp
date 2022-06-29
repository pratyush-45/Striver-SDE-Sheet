#include<bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int> maxHeap;
	for(int i= 0; i< n; i++){
        for(int j= 0; j< n; j++){
            maxHeap.push(a[i] + b[j]);
        }
    }
    
    vector<int> res;
    while(k--){
        res.push_back(maxHeap.top());
        maxHeap.pop();
    }
      
    return res;
}