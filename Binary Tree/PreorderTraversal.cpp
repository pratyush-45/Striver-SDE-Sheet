/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void preOrder(TreeNode *root, vector<int> &res){
    if(root == NULL)
        return;
    
    res.push_back(root->data);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> res;
    preOrder(root, res);
    return res;
}