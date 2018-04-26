
inline int max(int a, int b)
{
    return a>b?a:b;
}

int minDistance(char* word1, char* word2)
{
    if (strlen(word1)==0)
        return strlen(word2);
    if (strlen(word2)==0)
        return strlen(word1);
    
    int rc[501][501];
    for (int i=0;i<=strlen(word1);i++)
        for (int j=0;j<=strlen(word2);j++)
        {
            if(i == 0 || j == 0) 
                rc[i][j] = 0;
            else
            {
                rc[i][j] = word1[i-1]==word2[j-1] ?rc[i-1][j-1]+1:max(rc[i-1][j], rc[i][j-1]);
            }
        }
    return strlen(word1)+strlen(word2)-2*rc[strlen(word1)][strlen(word2)];
}