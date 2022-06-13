#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
     if(head == NULL || head->next == NULL || k == 0)
         return head;
    
    Node *temp = head;
    int len = 1;
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    temp->next = head;
    
    k = k % len;
    k = len - k;
    while(k--){
        temp = temp->next;
    }
    
    head = temp->next;
    temp->next = NULL;
    
    return head;
    
    
}