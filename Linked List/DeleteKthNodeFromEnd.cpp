#include <bits/stdc++.h> 
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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head == NULL || K == 0)  return head;
    
    
    LinkedListNode<int> *dummy = new LinkedListNode<int>(-1);
    dummy->next = head;
    LinkedListNode<int> *fast = dummy, *slow = dummy;
    
    for(int i= 1; i<= K; i++){
        fast = fast->next;
    }
    
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    LinkedListNode<int> *del = slow->next;
    slow->next = del->next;
    delete del;
    
    return dummy->next;
}