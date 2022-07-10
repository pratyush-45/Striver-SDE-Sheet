/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;
    if(root == NULL) return res;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        
        for(int i= 0; i< size; i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            
            int index = leftToRight ? i : size-1-i;
            level[index] = node->data;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        leftToRight = !leftToRight;
        for(auto it: level) 
            res.push_back(it);
    }
    
    return res;
}
