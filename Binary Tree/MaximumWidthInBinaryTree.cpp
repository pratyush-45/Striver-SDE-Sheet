/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        res = max(res, size);
        
        for(int i= 0; i< size; i++){
            TreeNode<int> *node = q.front();
            q.pop();
           
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    
    return res;
}