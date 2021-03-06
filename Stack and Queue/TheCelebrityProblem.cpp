/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>

int findCelebrity(int n)
 {
      stack<int>s;
      for(int i=0;i<n;i++)
          s.push(i);
            
      while(!s.empty() && s.size()>1)
      {
          int val1=s.top();
          s.pop();
          int val2=s.top();
          s.pop();
          knows(val1,val2)==true?s.push(val2):knows(val2,val1)==true?s.push(val1):void(0); 
      }

    if(!s.empty())
    {
        int val=s.top();
        int count=0;
        for(int i=0;i<n;i++) // check for celebrity row it should be 0  
        {
            if(knows(val,i)==true)
                 return -1;
        }
        
        for(int i=0;i<n;i++) // check for celebrity col 
        {
            if(knows(i,val)==true)
                count++;
        }
        if(count>=1)
             return val;
    }
      return -1;     
}