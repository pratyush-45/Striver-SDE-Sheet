/*************************************************************
 
    Following is the Binary Tree node structure

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

void inorder(BinaryTreeNode<int> *root, vector<BinaryTreeNode<int>*> &helper){
    if(root == NULL) return;
    
    inorder(root->left,helper);
    helper.push_back(root);
    inorder(root->right,helper);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    vector<BinaryTreeNode<int>*> helper;
    inorder(root,helper);
    for(int i=0;i<helper.size();i++){
        if(i==helper.size()-1){
            helper[i]->left=helper[i-1];
            helper[i]->right=NULL;
            continue;
        }
        if(i==0){
            helper[i]->right=helper[i+1];
            helper[i]->left=NULL;
            continue;
        }
        helper[i]->left=helper[i-1];
        helper[i]->right=helper[i+1];
    }
    
    return helper[0];
}