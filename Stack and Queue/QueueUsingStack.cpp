#include<bits/stdc++.h>
class Queue {
    stack<int> input, output;
    public:
    Queue() {
    }

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        
        if(output.empty())
            return -1;
        
        int n = output.top();
        output.pop();
        return n;
    }

    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        
        if(output.empty())
            return -1;
        
        return output.top();
    }

    bool isEmpty() {
        if(input.empty() && output.empty())
            return true;
        return false;
    }
};