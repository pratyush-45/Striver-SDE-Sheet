/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>

TreeNode<int>* buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &inMap){
        
    if(ps > pe || is > ie)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(postorder[pe]);
    int inRoot = inMap[postorder[pe]];
    int numsLeft = inRoot - is;

    root->left = buildTree(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, inMap);
    root->right = buildTree(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, inMap);

    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	if(inorder.size() != postorder.size())
            return NULL;
        
    map<int, int> inMap;
    for(int i= 0; i< inorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
}
