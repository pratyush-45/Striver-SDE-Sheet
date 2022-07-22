#include<bits/stdc++.h>

class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) {
       for(auto it: arr)
           pq.push(it);
    }

    void add(int num) {
        if(num <= pq.top())
            return;
        pq.push(num);
        pq.pop();
    }

    int getKthLargest() {
       return pq.top();
    }

};