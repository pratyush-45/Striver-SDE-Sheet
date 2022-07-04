string longestCommonPrefix(vector<string> &arr, int n)
{
    string res = "";
        
    for(int i= 0; i< arr[0].size(); i++){
        char ch = arr[0][i];
        
        for(string s: arr){
            if(i == s.length() || ch != s[i])
                return res;
        }
         
        res += ch;
    }

    return res;
}


