/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> res;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> todo;
    
    if(root == NULL) return res;
    
    todo.push(make_pair(root, make_pair(0,0)));
    while(!todo.empty()){
        auto temp = todo.front();
        todo.pop();
        TreeNode<int>* node = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        
        nodes[x][y].push_back(node->data);
        
        if(node->left)
            todo.push(make_pair(node->left, make_pair(x-1, y+1)));
        if(node->right) 
            todo.push(make_pair(node->right, make_pair(x+1, y+1)));
    }
    
    for(auto i : nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                res.push_back(k);
            }
        }
    }
    
    return res;
}