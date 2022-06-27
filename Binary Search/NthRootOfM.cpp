long double multiply(long double number, int n){
    long double res = 1.0;
    for(int i= 1; i<= n; i++){
        res *= number;
    }
    return res;
}

double findNthRootOfM(int n, long long m) {
	long double low = 1.0;
    long double high = (long double)m;
    long double esp = 1e-9;
    
    while((high - low) > esp){
        long double mid = low + (high - low)/ 2.0;
        if(multiply(mid, n) > (long double)m)
            high = mid;
        else
            low = mid;
    }
    
    return low;
}
