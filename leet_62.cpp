class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0 || n==0)
            return 0;
        vector<vector<int>> map(m,vector<int>(n,0));
        map[0][0]=1;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
            {
                map[i][j]+=i>0?map[i-1][j]:0;
                map[i][j]+=j>0?map[i][j-1]:0;
            }
        return map[m-1][n-1];
    }
};
