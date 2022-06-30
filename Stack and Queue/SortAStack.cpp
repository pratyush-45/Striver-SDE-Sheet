void insert(int n, stack<int> &stack){
    if(stack.empty() || n > stack.top()){
        stack.push(n);
        return;
    }
    
    int x = stack.top();
    stack.pop();
    insert(n, stack);
    stack.push(x);
}

void sortStack(stack<int> &stack)
{
	if(stack.size() < 2)
        return;
    
    int n = stack.top();
    stack.pop();
    
    sortStack(stack);
    insert(n, stack);
}