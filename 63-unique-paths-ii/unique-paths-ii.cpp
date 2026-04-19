class Solution {
public:
vector<vector<int>>grid;
int m,n;
int dp[105][105];
int f(int i,int j){
    if (i >= m || j >= n) return 0;// ye dekh rha hai khi chalte chalte grid k bahar to nhi nikal gya 

    if (grid[i][j] == 1) return 0;
int ans=0;
    
    if (i == m-1 && j == n-1) return 1;// ye mtlb valid hai ek rasta mil gya 
    if(dp[i][j]!=-1) return dp[i][j];

 
     ans=f( i+1, j) +  f( i, j+1);// robot ko chala rhe hai
           

           return dp[i][j]=ans;
    

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid=obstacleGrid;
          m=grid.size();
         n =grid[0].size();
        memset(dp,-1,sizeof dp);
        return f(0,0);
        
    }
};