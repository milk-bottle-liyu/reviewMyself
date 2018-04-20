int printdata(int* nums, int numsSize)
{
    for (int i=0;i<numsSize;i++)
        printf("%d ",nums[i]);
    printf("\n");
    return 0;
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int i,tmp,tmp2;
    for (i=0;i<numsSize;i++)
    {
        if (nums[i]!=0)
        {
            tmp=nums[i];
            while (tmp && (tmp-1)>i)
            {
                tmp2=nums[tmp-1];
                nums[tmp-1]=0;
                tmp=tmp2;
                // printf("%d\n",tmp);
                // printdata(nums,  numsSize);
            }
            if (tmp-1>=0)
                nums[tmp-1]=0;
            // printf("%d\n",tmp);
            // printdata( nums, numsSize);
            // printf("HHHHHHHHHHHHHHHHHHHHH\n");
        }
    }

    tmp=0;
    for (i=0;i<numsSize;i++)
        if (nums[i])
        {
            tmp++;
        }
    int * rc;
    *returnSize=tmp;
    rc=(int*)malloc(sizeof(int)*tmp);
    tmp=0;
    for (i=0;i<numsSize;i++)
        if (nums[i])
        {
            rc[tmp]=i+1;
            tmp++;
        }
    return rc;
    
}