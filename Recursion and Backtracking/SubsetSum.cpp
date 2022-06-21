void solve(vector<int> &num, int ind, int n, vector<int> &res, int sum){
        if(ind == n){
            res.push_back(sum);
            return;
        }
        
        solve(num, ind+1, n, res, sum+num[ind]);
        solve(num, ind+1, n, res, sum);
    }

vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    solve(num, 0, num.size(), res, 0);
    sort(res.begin(), res.end());
    return res;
}