#include<bits/stdc++.h>
bool isAllocationPossible(int n, int m, vector<int> &time, long long mid){
    int dayCnt = 1;
    long long reqTime = 0;
    for(int i= 0; i< m; i++){
        if(reqTime + time[i] <= mid){
            reqTime += time[i];
        }
        else{
            dayCnt++;
            if(dayCnt > n || time[i] > mid)
                return false;
            reqTime = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long low = 0;
    long long high = 0;
    for(int i= 0; i< time.size(); i++){
        high += time[i];
    }
    long long ans = -1;
    
    while(low <= high){
        long long mid = low + (high-low)/ 2;
        if(isAllocationPossible(n, m, time, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}