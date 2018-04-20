void moveZeroes(int* nums, int numsSize)
{
    int idx=0,insert_idx=0;
    while(idx<numsSize)
    {
        if (nums[idx]==0)
            idx++;
        else
        {
            if (idx==insert_idx)
            {
                idx++;
                insert_idx++;
            }
            else
            {
                nums[insert_idx]=nums[idx];
                idx++;
                insert_idx++;
            }
        }
    }
    for (int i=insert_idx;i<numsSize;i++)
        nums[i]=0;
    return ;
}