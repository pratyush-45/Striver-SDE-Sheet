#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> s;
    int count = 0;
    for(auto it: arr){
        s.insert(it);
    }
    
    for(auto it: arr){
        if(!s.count(it - 1)){
            int curNum = it;
            int curCount = 1;
            
            while(s.count(curNum + 1)){
                curNum++;
                curCount++;
            }
            
            count = max(count, curCount);
        }
    }
    
    return count;
}