inline int max(int a,int b)
{
    if (a<b)
        return b;
    return a;
}

int rob(int* nums, int numsSize) 
{
    if (numsSize<=0)
        return 0;
    if (numsSize==1)
        return nums[0];
    int rc[2],tmp;
    rc[0]=0;
    rc[1]=nums[0];
    for (int i=1;i<numsSize;i++)
    {
        tmp=max(rc[0],rc[1]);
        rc[1]=rc[0]+nums[i];
        rc[0]=tmp;
    }
    return max(rc[0],rc[1]);
}