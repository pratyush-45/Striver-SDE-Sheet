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
TreeNode<int>* TreeCreator(vector<int>& arr ,int low, int n){
    if(low > n)
        return NULL;

    int mid = (n + low)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    root->left = TreeCreator(arr, low, mid-1);
    root->right = TreeCreator(arr, mid+1, n);

    return root;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return TreeCreator(arr, 0, n-1);
}