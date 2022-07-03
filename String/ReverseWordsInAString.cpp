#include<bits/stdc++.h>

string reverseString(string str)
{
    str += " ";
    stack<string> st;
    string res = "";
    string temp = "";
    
    for(int i= 0; i< str.size(); i++){
        if(str[i] != ' '){
            temp += str[i];
        }
        else if(str[i+1] != ' '){
            st.push(temp);
            temp = "";
        }
    }
    
    while(!st.empty()){
        if(st.size() > 1)
            res += st.top() + " ";
        else
            res += st.top();
        st.pop();
    }
    
    return res;
}