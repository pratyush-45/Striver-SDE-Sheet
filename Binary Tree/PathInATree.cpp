/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool getPath(TreeNode<int> *node, int x, vector<int> &res){
    if(node == NULL) return false;
    
    res.push_back(node->data);
    
    if(node->data == x) return true;
    
    if(getPath(node->left, x, res) || getPath(node->right, x, res))
        return true;
    
    res.pop_back();
    
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res;
    if(root == NULL) return res;
    
    getPath(root, x, res);
    return res;
}
