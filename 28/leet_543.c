/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
inline int max(int a,int b)
{
    if (a<b) return b;
    return a;
}

int dfs(struct TreeNode * node,int *depth)
{
    if (node==NULL)
    {
        *depth=0;
        return 0;
    }
    int leftD,rightD,rcL,rcR;

    rcL=dfs(node->left,&leftD);
    
    rcR=dfs(node->right,&rightD);
    
    *depth=max(leftD,rightD)+1;
    rcL=max(rcL,rcR);
    rcL=max(rcL,leftD+rightD);
    // printf("%d:%d %d\n",node->val,rcL,*depth);
    return rcL;
}

int diameterOfBinaryTree(struct TreeNode* root) 
{
    if (root==NULL)
        return 0;
    int d;
    return dfs(root,&d);
}