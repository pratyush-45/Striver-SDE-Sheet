#include<bits/stdc++.h>

void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    if(n == 0)
        return;
    
    maxHeap.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i= 1; i< n; i++)
    {
        int x = arr[i];
        if(maxHeap.size() > minHeap.size()){
            if(maxHeap.top() > x){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
            }
            cout<<(((int)maxHeap.top()+minHeap.top())/2)<<" ";
        }
        else{
            if(x <= maxHeap.top()){
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            cout<<maxHeap.top()<<" ";
        }
    }
}