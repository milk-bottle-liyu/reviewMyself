void travel(struct TreeNode* root,int *rc,int *returnSize)
{
    if (root!=NULL)
    {
        travel(root->left,rc,returnSize);
        rc[*returnSize]=root->val;
        (*returnSize)++;
        travel(root->right,rc,returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int idx=0;
    int rc=malloc(sizeof(int)*4000);
    
    *returnSize=0;
    
    travel(root,rc,returnSize);
    
    return rc;
}