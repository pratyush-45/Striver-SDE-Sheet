/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
 LinkedListNode<int>* reverseList(LinkedListNode<int> *head) {
        if(head == NULL) return NULL;
        
        LinkedListNode<int> *p = NULL, *c = head, *n = head->next;
        while(c != NULL){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
        return p;
    }
bool isPalindrome(LinkedListNode<int> *head) {
     if(head == NULL||head->next == NULL) return true;
    
	LinkedListNode<int> *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        
        LinkedListNode<int> *start = head, *mid = slow->next;
        while(mid != NULL){
            if(mid->data != start->data) return false;
            start = start->next;
            mid = mid->next;
        }
        
       slow->next = reverseList(slow->next);
        return true;
}