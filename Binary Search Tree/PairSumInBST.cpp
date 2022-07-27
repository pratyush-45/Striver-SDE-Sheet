/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>

void inorder(BinaryTreeNode<int> *root, unordered_map<int,int>& m){
    if(!root) return;

    inorder(root->left, m);
    m[root->data]++;
    inorder(root->right, m);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_map<int,int> m;
    inorder(root, m);

    for(auto x : m)
    {
        int num = k - x.first;
        m[x.first]--;
        if(m.find(num) != m.end() && m[num] >= 1)
            return true;
        
        m[x.first]++;
    }
    
    return false;
}