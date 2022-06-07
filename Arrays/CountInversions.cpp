long long int count = 0;
void merge(long long *arr, long long low, long long mid, long long high)
{
         long long n1 = mid-low+1;
         long long n2 = high-mid;
         long long left[n1], right[n2];
    
         for(long long i = 0; i < n1; i++)
            left[i] = arr[low+i];
         for(long long i = 0; i < n2; i++)
            right[i] = arr[mid+i+1];
        
        int i = 0, j = 0, k = low;
        while(i < n1 && j < n2)
        {
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else
            {
                 arr[k++] = right[j++];
                 count += (n1-i);
            }
        }
        while(i < n1)
        {
            arr[k++] = left[i++];
        }
        while(j < n2)
        {
            arr[k++] = right[j++];
        }
}

void mergeSort(long long *arr, long long low, long long high)
{
        if(low < high){
            long long mid = (low+high)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
    
            merge(arr, low, mid, high);
        }
        else{
            return;
        }   
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    mergeSort(arr, 0, n-1);
    return count;
}