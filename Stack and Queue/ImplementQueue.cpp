class Queue {
    int *arr, start, end, size;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        start = 0;
        end = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(start == end)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        if(end == size)
            cout<<"Queue is already full";
        else{
            arr[end] = data;
            end++;
        }
    }

    int dequeue() {
        if(start == end)
            return -1;
        else{
            int res = arr[start];
            arr[start] = -1;
            start++;
            if(start == end){
                start = 0;
                end = 0;
            }
            return res;
        }
    }

    int front() {
        if(start == end)
            return -1;
        else
            return arr[start];
    }
};