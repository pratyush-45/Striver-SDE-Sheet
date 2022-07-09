/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
#include<bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res;
    vector<int> in, pre, post;
    if(root == NULL) return res;
    stack<pair<BinaryTreeNode<int>*, int>> st;
    st.push({root, 1});
    
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        
        // PreOrder
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left)
                st.push({it.first->left, 1});
        } // InOrder
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push({it.first->right, 1});
        } // PostOrder
        else if(it.second == 3){
            post.push_back(it.first->data);
        }
    }
    
    res.push_back(in);
    res.push_back(pre);
    res.push_back(post);
    
    return res;
}