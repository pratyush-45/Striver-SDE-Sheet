#include<bits/stdc++.h>
class Stack {
    queue<int> q;
   public:
    Stack() {
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        q.push(element);
        for(int i= 0; i< q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty())
            return -1;
        
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        if(q.empty())
            return -1;
        return q.front();
    }
};