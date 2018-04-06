char* convert(char* s, int numRows)
{
    if (strlen(s)==0)
        return "";
    if (numRows==1)
        return s;
    int loopLen=numRows*2-2;
    int len=strlen(s);
    int loopNum=(len-1)/loopLen+1;
    int tail=len-(loopNum-1)*loopLen;
    int offset[1000];
    memset(offset,0,1000*4);
    for (int i=0;i<tail;i++)
        offset[numRows-1-abs(i-numRows+1)]++;
    offset[0]+=loopNum-1;
    for (int i=1;i<numRows-1;i++)
        offset[i]+=2*(loopNum-1);
    
    for (int i=1;i<numRows-1;i++)
        offset[i]+=offset[i-1];
    for (int i=0;i<numRows;i++)
        printf("%d\n",offset[i]);
    char *rc=malloc(len+1);
    memset(rc,0,len+1);
    int loc[2];
    
    for (int idx=0;idx<len;idx++)
    {
        loc[0]=idx/loopLen;
        loc[1]=idx%loopLen;
        loc[1]=loc[1]<numRows?loc[1]:-(numRows-1-abs(loc[1]-numRows+1));
        
        if (loc[1]==0)
        {
            rc[loc[0]]=s[idx];
        }
        else if(loc[1]==numRows-1)
        {
            rc[loc[0]+offset[numRows-2]]=s[idx];
        }
        else if (loc[1]>0)
        {
            rc[loc[0]*2+offset[loc[1]-1]]=s[idx];
        }
        else
        {
            rc[loc[0]*2+offset[-loc[1]-1]+1]=s[idx];
        }
    }
    // printf("%s\n",s);
    // printf("%s\n",rc);
    return rc;
    
}