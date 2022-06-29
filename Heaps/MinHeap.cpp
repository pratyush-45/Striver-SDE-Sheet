vector<int> minHeap(int n, vector<vector<int>>& q) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for(auto it: q){
        if(it[0] == 0){
            pq.push(it[1]);
        }
        else if(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
    }
    
    return res;
}
