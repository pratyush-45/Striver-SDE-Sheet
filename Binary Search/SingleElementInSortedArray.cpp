int uniqueElement(vector<int> arr, int n)
{
	int low = 0, high = n-1;
    while(low <= high){
        int mid = (high + low)/ 2;
        
        if(arr[mid] == arr[mid ^ 1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return arr[low];
}
