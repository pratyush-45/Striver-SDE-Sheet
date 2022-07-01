#include<bits/stdc++.h>

class minStack
{
	stack<pair<int, int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			int mini;
            if (st.empty()) {
                mini = num;
            } 
            else{
                mini = min(st.top().second, num);
            }
            st.push({num, mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(st.empty())
                return -1;
			int x = st.top().first;
            st.pop();
            return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{    
            if(st.empty())
                return -1;
		    return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{    
            if(st.empty())
                return -1;
			return st.top().second;
		}
};