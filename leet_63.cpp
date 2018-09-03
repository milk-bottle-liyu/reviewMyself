class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]==1 ||obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)
            return 0;
        obstacleGrid[0][0]=-1;
        for (int i=0;i<obstacleGrid.size();i++)
            for (int j=0;j<obstacleGrid[0].size();j++)
            if (obstacleGrid[i][j]==0)
            {
                obstacleGrid[i][j]+=(i>0 && obstacleGrid[i-1][j]<0)?obstacleGrid[i-1][j]:0;
                obstacleGrid[i][j]+=(j>0 && obstacleGrid[i][j-1]<0)?obstacleGrid[i][j-1]:0;
            }        
        return -obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
