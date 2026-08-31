class Solution {
public:
int dp[105][105];
    int f(int i, int j, vector<vector<int>>& obstacleGrid) {

        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

            if(dp[i][j]!=-1) return dp[i][j];



        int up = f(i - 1, j, obstacleGrid);

        int left = f(i, j - 1, obstacleGrid);

        return  dp[i][j]=up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(n - 1, m - 1, obstacleGrid);
    }
};