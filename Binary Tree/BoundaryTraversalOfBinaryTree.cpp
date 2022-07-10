/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>

bool isLeaf(TreeNode<int>* root){
    return (root->left == NULL) && (root->right == NULL);
}

void addLeftBoundry(TreeNode<int>* root, vector<int> &res){
    TreeNode<int> *cur = root->left;
    while(cur){
        if(!isLeaf(cur)) 
            res.push_back(cur->data);
        if(cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundry(TreeNode<int>* root, vector<int> &res){
    TreeNode<int> *cur = root->right;
    stack<int> st;
    while(cur){
        if(!isLeaf(cur)) 
            st.push(cur->data);
        if(cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaves(root->left, res);
    if(root->right)
        addLeaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    
    if(!isLeaf(root))
        res.push_back(root->data);
    
    addLeftBoundry(root, res);
    addLeaves(root, res);
    addRightBoundry(root, res);
    
    return res;
}