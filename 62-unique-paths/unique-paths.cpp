class Solution {
public:
int M,N;
vector<vector<int>>dp;

int f(int i,int j) 
{
    if(i==M|| j==N) return 0;
    if(i==M-1 && j==N-1) return 1;
    if(dp[i][j] !=-1) return dp[i][j];

    int right=f(i,j+1);
    int down=f(i+1,j);
    return  dp[i][j]=right+down;
    
}
    int uniquePaths(int m, int n) {
        M=m;N=n;
        dp.assign(m,vector<int>(n,-1));
         return f(0,0);
        
    }
};