#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    vector<int> m(256, -1);
    int n = input.size();
    int left = 0, right = 0;
    int len = 0;
    
    while(right < n){
        if(m[input[right]] != -1){
            left = max(m[input[right]]+1, left);
        }
        
        m[input[right]] = right;
        
        len = max(len, right-left+1);
        right++;
    }
    
    return len;
}