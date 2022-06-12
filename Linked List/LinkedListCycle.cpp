/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
	Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(fast == NULL || fast->next == NULL)
        return NULL;
    slow = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}