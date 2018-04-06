char* longestPalindrome(char* s) {
    int rc[2000][2];
    int l=strlen(s);
    
    if (s[0]=='\0')
    {
        return NULL;
    }
    else
    {
        int idx=0;
        for (int i=0;i<(2*l-1);i++)
        {
            for (idx=(i+1)/2-1;(idx>=0 && i-idx<l)  && s[idx]==s[i-idx];idx--)
                ;
            idx++;
            rc[i][0]=i-2*idx+1;
            rc[i][1]=idx;
        }
    }
    
    int mx=0,mxIdx;
    for (int i=0;i<2*l-1;i++)
    {
        if (rc[i][0]>mx)
        {
            mx=rc[i][0];
            mxIdx=rc[i][1];
        }
    }
    // for (int i=0;i<2*l-1;i++)
    //     printf("%d",rc[i][0]);
    // printf("\n");
    // for (int i=0;i<2*l-1;i++)
    //     printf("%d",rc[i][1]);
    // printf("\n");
    // for (int i=mxIdx;i<(mxIdx+mx-1);i++)
    //     printf("%c",s[i]);
    
    s[mxIdx+mx]='\0';
    return s+mxIdx;
    
}