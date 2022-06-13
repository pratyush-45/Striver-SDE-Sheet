#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    
    for(int i= 0; i< n-2; i++){
        if(i == 0 || (i > 0 && arr[i] != arr[i-1])){
            int lo = i+1, hi = n-1;
            while(lo < hi){
                int sum = arr[i] + arr[lo] + arr[hi];
                if(sum == K){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[lo]);
                    temp.push_back(arr[hi]);
                    res.push_back(temp);
                    while(lo < hi && arr[lo] == arr[lo+1])
                        lo++;
                    while(lo < hi && arr[hi] == arr[hi-1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if(sum < K)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}