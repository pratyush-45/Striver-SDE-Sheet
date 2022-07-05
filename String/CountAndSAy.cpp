string writeAsYouSpeak(int n) 
{
    string res = "1";
    for (int i= 1; i< n; i++)
    {
        string temp = "";
        int cnt = 1;
        for (int j= 0; j< res.length()-1; j++)
        {
            if (res[j] == res[j+1])
                cnt++;
            else
            {
                temp += (to_string(cnt) + res[j]);
                cnt = 1;
            }
        }
       temp += to_string(cnt) + res[res.length()-1];
       res = temp;
    }
    
    return res;
}