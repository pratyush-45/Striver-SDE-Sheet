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
void recursion(TreeNode<int> *node, int level, vector<int> &res){
    if(node == NULL) return;
    
    if(level == res.size())
        res.push_back(node->data);
    recursion(node->left, level+1, res);
    recursion(node->right, level+1, res);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> res;
    recursion(root, 0, res);
    return res;
}