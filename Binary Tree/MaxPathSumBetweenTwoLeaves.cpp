/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

long long int maxPathDown(TreeNode<int> *node, long long int &maxi){
    if(node == NULL) return 0;
    
    long long int left = max(1LL*0, maxPathDown(node->left, maxi));
    long long int right = max(1LL*0, maxPathDown(node->right, maxi));
    
    maxi = max(maxi, left+right+node->val);
    return max(left, right) + node->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{    
    if(root == NULL || root->left == NULL || root->right == NULL) 
        return -1;
    
    long long int maxi = 0;
    maxPathDown(root, maxi);
    return maxi;
}