int countSubstrings(char* s) 
{
    if (s==NULL)
        return 0;
    int len=strlen(s);
    printf("%d\n",len);
    short *rc=(int *)malloc(sizeof(short)*len*len);
    int count=0;
    for (int i=0;i<len;i++)
        for (int j=0;j<(len-i);j++)
        {
            // if (i>2)
                
            if (i==0)
            {
                rc[j*len+j+i]=1;
                count++;
            }
            else
            {
                if ((i+1)%2==1)
                {
                    if (s[j]!=s[j+i])
                    {
                        rc[j*len+j+i]=0;
                    }
                    else
                    {
                        rc[j*len+j+i]=rc[(j+1)*len+j+i-1];
                        count+=rc[(j+1)*len+j+i-1];
                    }
                }
                else
                {
                    if (s[j]!=s[j+i])
                    {
                        rc[j*len+j+i]=0;
                    }
                    else
                    {
                        if (i==1)
                        {
                            rc[j*len+j+i]=1;
                            count++;
                        }
                        else
                        {
                            rc[j*len+j+i]=rc[(j+1)*len+j+i-1];
                            count+=rc[(j+1)*len+j+i-1];
                        }
                    }
                }
            }
            // printf("%d %d %d:%d\n",j,j+i,count,rc[j*len+j+i]);
        }
    return count;
}