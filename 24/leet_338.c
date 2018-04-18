int* countBits(int num, int* returnSize) {
    if (num<0)
    {
        *returnSize=0;
        return NULL;
    }
    
    int * rc=(int *) malloc(sizeof(int)*num+1);
    *returnSize=num+1;
    rc[0]=0;
    for (int i=1;i<=num;i++)
    {
        if (i%2==0)
            rc[i]=rc[i/2];
        else
            rc[i]=rc[i/2]+1;
    }
    
    return rc;
}