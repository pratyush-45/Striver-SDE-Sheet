#include<bits/stdc++.h> 

int largestRectangle(vector<int> &heights) {
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];

    //Finding leftsmallof all elements
    for(int i= 0; i< n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;

        st.push(i);
    }

    while(!st.empty())  //clesr the stsck for reuse
        st.pop();

    //Finding rightsmallof all elements
    for(int i= n-1; i>= 0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }

    int maxA = 0;
    for(int i= 0; i< n; i++){
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }

    return maxA;
 }