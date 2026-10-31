class Solution {
public:
int m,n;
typedef long long ll;

int f(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&dp){
    if(i>=m || j>=n) return INT_MAX;
    if(i==m-1 && j==n-1)  return grid[m-1][n-1];
    if(dp[i][j]!=-1) return dp[i][j];
    
    ll rightSum=(ll)grid[i][j]+f(i,j+1,grid,dp);
   ll downSum=(ll)grid[i][j]+ f(i+1,j,grid,dp);
    
   
    return  dp[i][j]=min(rightSum,downSum);
    

}
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
     
      
        return f(0,0,grid,dp);

        
    }
};