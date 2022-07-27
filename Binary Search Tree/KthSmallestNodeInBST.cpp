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

int kthSmallest(TreeNode<int> *root, int k)
{
    stack<TreeNode<int>*> st;
    
    while(root or !st.empty()){
        while(root){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if(--k == 0)
            break;
        root = root->right;
    }
    
    return root->data;
}