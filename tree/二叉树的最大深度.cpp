#include "commen.h"

class Solution
{
public:
    int max_depth = INT64_MIN;

    void inorder(TreeNode *root, int depth)
    {
        if(!root)
        {
            max_depth = max_depth > depth ? max_depth : depth;
            return;
        }
        depth++;
        inorder(root->left,depth);
        inorder(root->right,depth);
    }
    int maxDepth(TreeNode *root)
    {
        inorder(root,0);
        return max_depth;
    }
};
