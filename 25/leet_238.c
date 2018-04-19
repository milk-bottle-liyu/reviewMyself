/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int prod_begin=1,prod_end=1;
    
    int *rc=malloc(sizeof(int)*numsSize);
    
    for (int i=0;i<numsSize-1;i++)
    {
        prod_begin*=nums[i];
        rc[i+1]=prod_begin;
    }
    rc[0]=1;
    for (int j=numsSize-1;j>=0;j--)
    {
        prod_end*=nums[j];
        rc[j-1]*=prod_end;
    }
    
    *returnSize=numsSize;
    if (numsSize==1)
    {
        rc[0]=nums[0];
    }
    
    return rc;
}