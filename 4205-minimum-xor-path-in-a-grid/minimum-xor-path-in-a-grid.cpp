class Solution {
public:
int m,n;
vector<vector<vector<int>>>dp;
int f(int i,int j,int ans,vector<vector<int>>& grid){
    if(i==m || j==n) return INT_MAX;
    ans=ans^grid[i][j];
    if(i==m-1 && j==n-1) return ans;

    if(dp[i][j][ans] !=-1) return dp[i][j][ans];
    int right=f(i,j+1,ans,grid);
    int down=f(i+1,j,ans,grid);
    return dp[i][j][ans]= min(right,down);
}
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
       dp.assign(m,vector<vector<int>>(n,vector<int>(1024,-1)));
      
        return f(0,0,0,grid);


        
    }
};