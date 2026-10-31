class Solution {
public:

int  mod=1e9+7;
int left=0,up=1;
int m,n;
int dp[501][501][10];
int f(vector<vector<int>>& grid,int i,int j,int dir){
    if(i>=m || j>=n  ) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j][dir]!=-1) return dp[i][j][dir];
    if(grid[i][j]==0){

    
    int right=f(grid,i,j+1,left);
          int down=f(grid,i+1,j,up);
   
    return  dp[i][j][dir]=(right%mod + down%mod)%mod;
    }

    
    if(grid[i][j]==1){
        if(dir==left){
            int down=f(grid,i+1,j,up);
            return dp[i][j][dir]= down;
        }
        else{
            int right=f(grid,i,j+1,left);
            return dp[i][j][dir]=right;
        }
    }
   
   
     int right=f(grid,i,j+1,left);
          int down=f(grid,i+1,j,up);
   
    return  dp[i][j][dir]=(right+ down)%mod;
        
   
}

    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
       return f(grid,0,0,left);
      
        
    }
};