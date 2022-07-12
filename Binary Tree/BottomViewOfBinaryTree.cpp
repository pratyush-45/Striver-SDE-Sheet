/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> res;
    if(root == NULL) return res;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *node = it.first;
        int line = it.second;
        
        m[line] = node->data;
        
        if(node->left)
            q.push({node->left, line-1});
        if(node->right)
            q.push({node->right, line+1});
    }
    
    for(auto it: m){
        res.push_back(it.second);
    }
    
    return res;
}
