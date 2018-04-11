/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//慎用define，尽量用inline的内联函数，比如此处如果直接max(dfs...,dfs...),会导致dfs被计算4次，boom
#define max(x,y) x>y?x:y
int dfs(struct TreeNode * node)
{
    if (node==NULL)
        return 0;
    int t1=dfs(node->left);
    int t2=dfs(node->right);
    return 1+(max(t1,t2));
}
int maxDepth(struct TreeNode* root)
{
    return dfs(root);
}