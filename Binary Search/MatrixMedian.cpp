int countSmallerThanMid(vector<int> &row, int mid){
    int l = 0, h = row.size()-1;
    while(l <= h){
        int md = (h + l)/ 2;
        if(row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = 1, high = 1e9;
    int n = matrix.size(), m = matrix[0].size();
    
    while(low <= high){
        int mid = (high + low)/ 2;
        int cnt = 0;
        for(int i= 0; i< n; i++){
            cnt += countSmallerThanMid(matrix[i], mid);
        }
        
        if(cnt <= (n*m)/2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}