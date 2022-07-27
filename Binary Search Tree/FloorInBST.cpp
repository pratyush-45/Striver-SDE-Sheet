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

int floorInBST(TreeNode<int> * root, int X)
{
    TreeNode<int> *curr = root;
    int res = -1;
    
    while(curr) {
        if(curr -> val > X) {
            curr = curr -> left;
        } else {
            res = curr -> val;
            curr = curr -> right;
        }
    }
    
    return res;
}