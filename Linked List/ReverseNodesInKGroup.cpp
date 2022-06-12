#include <bits/stdc++.h> 
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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node *dummy = new Node(-1);
    dummy->next = head;
    
    Node *prev = dummy;
    Node *cur = dummy;
    Node *nex = dummy;
    
    int cnt = 0;
    while(cur->next != NULL){
        cur = cur->next;
        cnt++;
    }
    
    int j = 0;
    while(cnt> 0 && j< n){
        cur = prev->next;
        nex = cur->next;
        int x = (b[j] <= cnt) ? b[j] : cnt;
        if(x == 0){
            j++;
            continue;
        }
        for(int i=1;i<x;i++){
           cur->next = nex->next;
           nex->next = prev->next;
           prev->next = nex;
           nex = cur->next;
       }
        
       prev = cur;
       cnt -= b[j];
       j++;
    }
    
    return dummy->next;
}