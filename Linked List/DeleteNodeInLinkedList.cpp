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

void deleteNode(LinkedListNode<int> * node) {
    
    if(node->next == NULL) delete node;
    
    LinkedListNode<int> *temp = node->next;
    swap(node->data, temp->data);
    node->next = temp->next;
    delete temp;
}