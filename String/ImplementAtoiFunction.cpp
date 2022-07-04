#include<bits/stdc++.h>

int atoi(string str) {
    int sign = 1;
    int res = 0;
    int index = 0;
    int n = str.size();
    
    if(index < n && str[index] == '-'){
        sign = -1;
        index++;
    }

    for( ; index < n; index++){
        if(isdigit(str[index])){
            int digit = str[index] - '0';
            res = 10 * res + digit;
        }
    }

    return sign * res;
}