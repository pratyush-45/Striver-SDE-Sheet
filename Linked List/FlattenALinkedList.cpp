#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node *mergeTwoLists(Node *a, Node *b){
    Node *dummy = new Node(-1);
    Node *tail = dummy;
    
    while(a != NULL && b != NULL){
        if(a->data <= b->data){
            tail->child = a;
            a = a->child;
            tail = tail->child;
            tail->next = NULL;
        }
        else{
            tail->child = b;
            b = b->child;
            tail = tail->child;
            tail->next = NULL;
        }
    }
    if(a != NULL)
        tail->child = a;
    else
        tail->child = b;
    
    return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL)
        return head;
    
    head->next = flattenLinkedList(head->next);
    mergeTwoLists(head, head->next);
    
    return head;
}
