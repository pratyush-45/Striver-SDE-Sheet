#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    int ans = 1;
    
	while(n){
        if(n % 2 != 0){
            ans = (1LL* ans * x % m)%m;
            n--;
        }
        else{
            x = (1LL * x%m * x%m)%m;
            n = n/2;
        }
    }
    
    return ans;
}