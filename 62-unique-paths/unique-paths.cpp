class Solution {
public:
vector<vector<int>>dp;
int solve(int r,int c,vector<vector<int>>&grid,int m,int n){
    if(r>=m-1 ||  c>=n-1) return 1;
    if(dp[r][c]!=-1) return dp[r][c];
   return   dp[r][c]=solve(r+1,c,grid,m,n)+solve(r,c+1,grid,m,n);
}

    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        vector<vector<int>>grid(m,vector<int>(n));
         return solve(0,0,grid,m,n);
        
        
    }
};