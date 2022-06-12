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

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *a = firstHead, *b = secondHead;
    while(a != b){
        
        (a == NULL) ? a = secondHead : a = a->next;
        (b == NULL) ? b = firstHead : b = b->next;
        
    }
    
    if(a != NULL)
    	return a->data;
    return -1;
}