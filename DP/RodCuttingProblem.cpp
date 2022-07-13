int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int k=0;
        int j=i;
        dp[i]=price[i-1];
        while(k<=j)
        {
            dp[i] = max(dp[i],dp[j]+dp[k]);
            k++;
            j--;
        }
    }
    return dp[n];
}
