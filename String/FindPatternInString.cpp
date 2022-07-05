bool findPattern(string p, string s)
{  
    int n = s.size(), m = p.size();
    for(int i= 0; i<= n - m; i++){
        if(s.substr(i, m) == p)
            return true;
    }
    
    return false;
}