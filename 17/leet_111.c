/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int mn;

int dfs(struct TreeNode *node,int depth)
{
    if (node==NULL)
        return 0;
    if (node->right == NULL & node->left==NULL)
    {
        if (mn==-1 ||depth+1<mn)
            mn=depth+1;
        return 0;
    }

    
    if (mn!=-1 && depth >= mn)
        return 0;
    
    dfs(node->left,depth+1);
    dfs(node->right,depth+1);
    return 0;
}

int minDepth(struct TreeNode* root) 
{
    if (root==NULL)
        return 0;
    mn=-1;
    
    dfs(root,0);
    
    return mn;
}