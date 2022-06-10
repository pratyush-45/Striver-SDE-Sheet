class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i= 0; i< n; i++){
            int target_3 = target - nums[i];
            for(int j= i+1; j< n; j++){
                int target_2 = target_3 - nums[j];
                
                int front = j+1;
                int back = n-1;
                
                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    
                    if(two_sum < target_2) front++;
                    else if(two_sum > target_2) back--;
                    else{
                        vector<int> quad(4, 0);
                        
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        
                        while(front < back && nums[front] == quad[2]) front++;
                        while(front < back && nums[back] == quad[3]) back--;
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j])
                    j++;
            }
            while(i+1 < n && nums[i+1] == nums[i])
                    i++;
        }
        return res;
    }
};


// Here is the CodeStudio Solution that I submitted

#include<bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    
    unordered_map<int,pair<int,int>> m;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<n;j++)
        {
            m[arr[i]+arr[j]]=make_pair(i,j);
        }
    }
    
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x=arr[i]+arr[j];
            
            if(m.find(target-x)!=m.end())
            {
                pair<int,int> p=m[target-x];
                
                if(i!=p.first && i!=p.second && j!=p.first && j!=p.second)
                    return "Yes";
            }
        }
    }
    return "No";
}