class Solution {
public:

int  mod=1e9+7;
int left=0,up=1;
int m,n;

int f(vector<vector<int>>& grid,int i,int j,int dir, vector<vector<array<int,2>>>&dp){
//2 ->left
//3->up
    
    if(i>=m || j>=n  ) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j][dir]!=-1) return dp[i][j][dir];

    
    if(grid[i][j]==1){
        if(dir==left){
            int down=f(grid,i+1,j,up,dp);
            return dp[i][j][dir]= down%mod;
        }
        else{
            int right=f(grid,i,j+1,left,dp);
            return dp[i][j][dir]=right%mod;
        }
    }
   
   
     int right=f(grid,i,j+1,left,dp);
          int down=f(grid,i+1,j,up,dp);
   
    return  dp[i][j][dir]=(right%mod + down%mod)%mod;
        
   
}

    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
       vector<vector<array<int,2>>>dp(m+1,vector<array<int,2>>(n,{-1,-1}));
       return f(grid,0,0,left,dp);
      
        
    }
};