int zAlgorithm(string s, string p, int n, int m)
{
	int cnt = 0;
    for(int i= 0; i<= n - m; i++){
        if(p == s.substr(i, m))
            cnt++;
    }
    
    return cnt;
}