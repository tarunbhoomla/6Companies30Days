class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        find(node);
    
    }
    
    int find(Node * root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) {int x = root->data; root->data =0; return x;}
        
        int x = find(root->left) + find(root->right);
        
        int y = root->data;
        root->data = x;
        return y + x;
    }
};
