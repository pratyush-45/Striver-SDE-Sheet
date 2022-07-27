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

class BSTiterator
{    
    public:
        stack<TreeNode<int>*> st;
    
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }
    
    void pushAll(TreeNode<int> *node){
        while(node != NULL){
            st.push(node);
            node = node->left;
        }
    }

    int next()
    {
        TreeNode<int> *temp = st.top();
        st.pop();
        pushAll(temp->right);
        
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/