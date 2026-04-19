class Solution {
public:
int dp[105][105];
int f(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n){
    if (i >= m || j >= n) return 0;

    // obstacle
    if (obstacleGrid[i][j] == 1) return 0;

    // destination
    if (i == m-1 && j == n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    // move right + down
    return  dp[i][j]=f(obstacleGrid, i+1, j, m, n) +
           f(obstacleGrid, i, j+1, m, n);
    

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int  m=obstacleGrid.size();
        int n =obstacleGrid[0].size();
        memset(dp,-1,sizeof dp);
        return f(obstacleGrid,0,0,m,n);
        
    }
};