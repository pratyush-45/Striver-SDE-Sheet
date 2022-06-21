void findCombination(int ind, int k, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds){
    if(ind == arr.size()){
        if(k == 0)
            res.push_back(ds);
        return;
    }
    
    else{
        ds.push_back(arr[ind]);
        findCombination(ind+1, k-arr[ind], arr, res, ds);
        ds.pop_back();
        findCombination(ind+1, k, arr, res, ds);
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    vector<int> ds;
    findCombination(0, k, arr, res, ds);
    return res;
}