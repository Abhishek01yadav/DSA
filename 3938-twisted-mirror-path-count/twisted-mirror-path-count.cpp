class Solution {
public:
    int mod = 1e9 + 7;
    int left = 0, up = 1;
    int m, n;
    
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
     vector<vector<array<int,2>>> dp(m,vector<array<int,2>>(n,{0,0}));
      dp[0][0][left]=1;
      //0th row
      for(int col=1;col<n;col++){
        dp[0][col][left]=1;
        if(grid[0][col]==1){
            break;
        }
      }

//0th col
      for(int row=1;row<m;row++){
        dp[row][0][up]=1;
        if(grid[row][0]==1){
            break;
        }
      }

//rest of the dp
for(int row=1;row<m;row++){
    for(int col=1;col<n;col++){
        //left se aa sakte hai.
        if(grid[row][col-1]==1){
           dp[row][col][left]=dp[row][col-1][up];
        }
        else{
             dp[row][col][left]=(dp[row][col-1][up]+dp[row][col-1][left])%mod;
            
        }


        //up se aa sakte hai
        if(grid[row-1][col]==1){
             dp[row][col][up]=dp[row-1][col][left];
         
        }
        else{
             dp[row][col][up]=(dp[row-1][col][left]+dp[row-1][col][up]) %mod;
            
        }



    }
}

return (dp[m-1][n-1][left]+dp[m-1][n-1][up])%mod;

    }
};