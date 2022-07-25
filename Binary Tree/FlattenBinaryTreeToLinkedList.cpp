/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(root == NULL) return root;
    
    TreeNode<int>* Right = root->right;
    root->right = flattenBinaryTree(root->left);
    TreeNode<int>* temp = root;

    while(temp->right){
        temp=temp->right;
    }
    
    temp->right = flattenBinaryTree(Right);
    root->left = NULL;
    return root;
}