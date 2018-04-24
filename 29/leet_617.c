/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void mergeNode(struct TreeNode *t1Node, struct TreeNode *t2Node)
{
    if (t1Node==NULL)
        return;
    if (t1Node!=t2Node && t2Node!=NULL)
        t1Node->val=t1Node->val+t2Node->val;
    if (t1Node->left!=NULL)
    {
        if (t2Node!=NULL)
            mergeNode(t1Node->left,t2Node->left);
    }
    else
    {
        if (t2Node!=NULL)
        {
            t1Node->left=t2Node->left;
        }
    }
    if (t1Node->right!=NULL)
    {
        if (t2Node!=NULL)
            mergeNode(t1Node->right,t2Node->right);
    }
    else
    {
        if (t2Node!=NULL)
        {
            t1Node->right=t2Node->right;
        }
    }
    return ;
}
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) 
{
    if (t1==NULL)
        return t2;
    mergeNode(t1,t2);
    return t1;
}