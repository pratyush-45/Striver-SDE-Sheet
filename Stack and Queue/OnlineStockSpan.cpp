#include<bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> res(n);
    stack<pair<int, int>> st;
    
    for(int i= 0; i< n; i++){
        int cnt = 1;
        while(!st.empty() && price[i] >= st.top().first){
            cnt += st.top().second;
            st.pop();
        }
        st.push({price[i], cnt});
        res[i] = cnt;
    }
    
    return res;
}