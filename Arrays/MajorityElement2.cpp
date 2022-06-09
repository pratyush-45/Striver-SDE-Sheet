#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();
    int num1 = 0, num2 = 0;
    int count1 = 0, count2 = 0;
    
    for(auto it: arr){
        if(it == num1)
            count1++;
        else if(it == num2)
            count2++;
        else if(count1 == 0){
            num1 = it;
            count1 = 1;
        }
        else if(count2 == 0){
            num2 = it;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    count1 = count2 = 0;
    for(auto it: arr){
        if(it == num1)
            count1++;
        else if(it == num2)
            count2++;
    }
    
    if(count1 > n/3)
        res.push_back(num1);
    if(count2 > n/3)
        res.push_back(num2);
    
    return res;

}