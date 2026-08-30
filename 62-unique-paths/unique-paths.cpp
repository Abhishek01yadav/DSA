class Solution {
public:
int dp[105][105];
int f(int row,int col,int m,int n){
    if(row>=m || col>=n) return 0;
    if(row ==m-1 && col==n-1){
        return 1;
    }
    if(dp[row][col]!=-1) return dp[row][col];

    return  dp[row][col]=f(row+1,col,m,n)+ f(row,col+1,m,n);


}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
       
        return f(0,0,m,n);

       
        
        
    }
};