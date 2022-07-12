/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

#include<bits/stdc++.h>

void connectNodes(BinaryTreeNode< int > *root) {
    if(root == NULL) return;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        vector<BinaryTreeNode<int>*> level;
        
        for(int i= 0; i< size; i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            level.push_back(node);
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        
        for(int i= 0; i< size-1; i++){
            level[i]->next = level[i+1];
        }
    }
}