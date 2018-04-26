int islandPerimeter(int** grid, int gridRowSize, int gridColSize) 
{
    int rc=0;
    for (int i=0;i<gridRowSize;i++)
        for (int j=0;j<gridColSize;j++)
            if (grid[i][j]==1)
            {
                if (i==0 || grid[i-1][j]==0)
                    rc++;
                if (i==gridRowSize-1 || grid[i+1][j]==0)
                    rc++;
                if (j==0 || grid[i][j-1]==0)
                    rc++;
                if (j==gridColSize-1 || grid[i][j+1]==0)
                    rc++;
            }
    return rc;
}