#define max(x,y) x>y?x:y

int maxSubArray(int* nums, int numsSize) 
{
    if (numsSize==0)
        return 0;
    
    int rc[50000][2];
    rc[0][0]=nums[0];
    rc[0][1]=nums[0];
    
    for (int i=1;i<numsSize;i++)
    {
        if (rc[i-1][0]>0)
            rc[i][0]=rc[i-1][0]+nums[i];
        else
            rc[i][0]=nums[i];
        rc[i][1]=max(rc[i-1][1],rc[i-1][0]);
    }
    
    return max(rc[numsSize-1][0],rc[numsSize-1][1]);
}