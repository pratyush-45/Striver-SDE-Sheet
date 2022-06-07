#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xor1 = 0;
    int set_bit_no;
    
    int x = 0;
    int y = 0;
    
    xor1 = arr[0];
    for(int i= 1; i< n; i++){
        xor1 = xor1 ^ arr[i];
    }
    
    for(int i= 1; i<= n; i++){
        xor1 = xor1 ^ i;
    }
    
    set_bit_no = xor1 & ~ (xor1-1);
    
    for(int i= 0; i< n; i++){
        if(arr[i] & set_bit_no)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    for(int i= 1; i<= n; i++){
        if(i & set_bit_no)
            x = x ^ i;
        else
            y = y ^ i;
    }
    
    bool x_found = false;
    for(int i= 0; i< n; i++){
        if(arr[i] == x)
            x_found = true;
    }
    if(x_found)
        swap(x, y);
    
    return {x, y};
}
