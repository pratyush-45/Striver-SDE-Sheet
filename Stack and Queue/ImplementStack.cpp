// Stack class.
class Stack {
    int size, *arr, topp;
public:
    
    Stack(int capacity) {
        topp = -1;
        size = capacity;
        arr = new int[size];
    }

    void push(int num) {
        if(size - topp != 1)
            arr[++topp] = num;
    }

    int pop() {
        if(topp != -1){
            int x = arr[topp];
            topp--;
            return x;
        }
        return -1;
    }
    
    int top() {
        if(topp != -1){
            int x = arr[topp];
            return x;
        }
        return -1;
    }
    
    int isEmpty() {
        if(topp == -1)
            return 1;
        return 0;
    }
    
    int isFull() {
        if(size - topp == 1)
            return 1;
        return 0;
    }
    
};