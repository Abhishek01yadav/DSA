class Solution {
public:
vector<vector<int>>grid2;
int dp[205][205];
int m,n;
int f(  int i,int j){
    if(i==m-1 && j==n-1) return  grid2[i][j];
    if(i>=m || j>=n) return 1e9;
    int ans=0;
    if (dp[i][j]!=-1) return dp[i][j];
     int right=grid2[i][j]+f(i+1,j);
    int down=grid2[i][j]+f(i,j+1);
    ans+=min(right,down);
    
    
    return dp[i][j]= ans;
}

    int minPathSum(vector<vector<int>>& grid) {
        grid2=grid;
         m=grid2.size();
         n=grid2[0].size();
         memset(dp,-1,sizeof dp);
       return   f(0,0);

        
    }
};