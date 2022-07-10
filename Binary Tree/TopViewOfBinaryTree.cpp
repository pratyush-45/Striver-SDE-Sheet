/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> res;
    if(root == NULL)  return res;
    map<int, int> m;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int line = it.second;

        if(m.find(line) == m.end())
            m[line] = node->val;
        
        if(node->left)
            q.push({node->left, line-1});
        if(node->right)
            q.push({node->right, line+1});
    }

    for(auto it: m){
        res.push_back(it.second);
    }

    return res;
}