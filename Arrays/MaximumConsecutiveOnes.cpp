int longestSubSeg(vector<int> &arr , int n, int k){
    int j = -1;
    int zeroCnt = 0;
    int res = 0;
    
    for(int i= 0; i< n; i++){
        if(arr[i] == 0)
            zeroCnt++;
        
        while(zeroCnt > k){
            j++;
            if(arr[j] == 0)
                zeroCnt--;
        }
        
        res = max(res, i-j);
    }
    
    return res;
}
