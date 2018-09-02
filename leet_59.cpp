class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rc(n, vector<int>(n));
        int x=0, y = 0,dir_idx=0;
        int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
        for (int i = 0; i < n*n; i++)
        {
            rc[x][y] = i + 1;
            if (x + dir[dir_idx][0] < 0 || x + dir[dir_idx][0] >= n
                || y + dir[dir_idx][1] < 0 || y + dir[dir_idx][1] >= n ||
                rc[x + dir[dir_idx][0]][y + dir[dir_idx][1]] != 0)
            {
                dir_idx = (dir_idx + 1) % 4;
            }
            x += dir[dir_idx][0];
            y += dir[dir_idx][1];
        }

        return rc;
    }
};
