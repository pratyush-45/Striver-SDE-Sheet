bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(auto it: expression){
        if(it == '{' || it == '(' || it == '['){
            st.push(it);
        }
        else{
            if(st.empty())
                return false;
            
            char ch = st.top();
            st.pop();
            if((ch == '{' && it == '}') || (ch == '(' && it == ')') || (ch == '[' && it == ']'))
                continue;
            else
                return false;
        }
    }
    
    return st.empty();
}