#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    vector<int> tempInterval = intervals[0];
    
    for(auto it: intervals){
        if(it[0] <= tempInterval[1]){
            tempInterval[1] = max(tempInterval[1], it[1]);
        }
        else{
            res.push_back(tempInterval);
            tempInterval = it;
        }
    }
    res.push_back(tempInterval);
    
    return res;
}
