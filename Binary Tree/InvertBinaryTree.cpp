/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

bool helper(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int>*> &st){
    st.push(root);
    
    if(root->left == NULL && root->right == NULL){
        if(root->data == leaf->data)
            return true;
        else{
            st.pop();
            return false;
        }
    }
    
    if(root->left){
        if(helper(root->left, leaf, st))
            return true;
    }
    if(root->right){
        if(helper(root->right, leaf, st))
            return true;
    }
    st.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(root == NULL) return root;
    
    stack<TreeNode<int>*> st;
    bool flag = helper(root, leaf, st);
    TreeNode<int> *newRoot = st.top();
    st.pop();
    
    TreeNode<int> *temp = newRoot;
    while(!st.empty()){
        TreeNode<int> *cur = st.top();
        st.pop();
        
        if(cur->left == temp){
            cur->left = NULL;
            temp->left = cur;
        }
        else{
            cur->right = cur->left;
            cur->left = NULL;
            temp->left = cur;
        }
        temp = cur;
    }
    
    return newRoot;
}
