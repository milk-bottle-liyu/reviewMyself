#define max(x,y) x>y?x:y

int lengthOfLongestSubstring(char* s) 
{
    // s="dvdf";
    int size;
    size=strlen(s);
    if (size==0)
        return 0;
    int rc1[50000],rc2[50000],late=0;
    short flag[256];
    memset(flag,0,256*sizeof(short));
    // memset(rc1,0,50000*sizeof(int));
    // memset(rc2,0,50000*sizeof(int));
    rc2[0]=1;
    flag[(short)s[0]]=1;
    // printf("%d %d\n",rc1[0],rc2[0]);
    // printf("%d %d %d %d\n",flag['a'],flag['b'],flag['c'],flag['d']);
    for (int i=1;i<size;i++)
    {
        if (late <  flag[(short)s[i]])
        {
            rc1[i]=max(rc1[i-1],rc2[i-1]);
            rc2[i]=i-flag[(short)s[i]]+1;
           // memset(flag,0,sizeof(short)*256);
            // for (int j=0;j<256;j++)
            //     if (flag[j]<flag[(short)s[i]]) flag[j]=0;
            late=flag[(short)s[i]];
            flag[(short)s[i]]=i+1;
        }
        else
        {
            rc1[i]=rc1[i-1];
            rc2[i]=rc2[i-1]+1;
            flag[(short)s[i]]=i+1;
        }
        // printf("%d %d\n",rc1[i],rc2[i]);
        // printf("%d %d %d %d\n",flag['a'],flag['b'],flag['c'],flag['d']);
    }
        
    
    return max(rc1[size-1],rc2[size-1]);
}