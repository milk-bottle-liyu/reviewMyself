int climbStairs(int n) 
{
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    if (n==2)
        return 2;
    
    int rc[3];
    rc[0]=1;
    rc[1]=2;
    for (int i=3;i<=n;i++)
    {
        rc[2]=rc[1]+rc[0];
        rc[0]=rc[1];
        rc[1]=rc[2];
    }
    return rc[1];
}