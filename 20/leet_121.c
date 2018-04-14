int maxProfit(int* prices, int pricesSize) 
{
    if (pricesSize<=1)
        return 0;
    int rc[2];
    rc[0]=prices[0];
    rc[1]=0;
    
    for (int i=1;i<pricesSize;i++)
    {
        if (prices[i]-rc[0]>rc[1])
            rc[1]=prices[i]-rc[0];
        if (prices[i]<rc[0])
            rc[0]=prices[i];
    }
    
    return rc[1];
}