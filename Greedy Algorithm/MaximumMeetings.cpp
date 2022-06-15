#include<bits/stdc++.h>

struct meeting{
    int start;
    int end;
    int pos;
};
static bool cmp(struct meeting m1, struct meeting m2){
    if(m1.end == m2.end)
        return m2.pos > m1.pos;
    else
        return m2.end > m1.end;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    struct meeting meet[n];
    vector<int> res;
    
    for(int i= 0; i< n; i++){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i+1;
    }
    sort(meet, meet+n, cmp);
    
    int limit = meet[0].end;
    res.push_back(meet[0].pos);
    
    for(int i= 1; i< n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            res.push_back(meet[i].pos);
        }
    }
    
    return res;
}