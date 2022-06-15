#include<bits/stdc++.h>

struct job{
    int start;
    int end;
};
static bool cmp(struct job j1, struct job j2){
    return j2.end > j1.end;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    struct job j[n];
    
    for(int i= 0; i< n; i++){
        j[i].start = start[i];
        j[i].end = finish[i];
    }
    sort(j, j+n, cmp);
    
    int res = 1;
    int limit = j[0].end;
    
    for(int i= 1; i< n; i++){
        if(j[i].start >= limit){
            limit = j[i].end;
            res++;
        }
    }
    
    return res;
}