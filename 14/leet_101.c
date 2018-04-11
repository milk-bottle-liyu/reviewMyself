/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode * left,struct TreeNode * right)
{
    if (left==NULL && right==NULL)
        return true;
    if (left==NULL || right==NULL || left->val!=right->val)
        return false;
    if ((left->left==NULL && right->right!=NULL) ||(left->left!=NULL && right->right==NULL))
        return false;
    
    if ((left->right==NULL && right->left!=NULL) ||(left->right!=NULL && right->left==NULL))
        return false;
    
    return (check(left->left,right->right) && check(left->right,right->left));
}

bool isSymmetric(struct TreeNode* root) 
{
    if (root==NULL)
        return true;
    
    return (check(root->left,root->right));
}