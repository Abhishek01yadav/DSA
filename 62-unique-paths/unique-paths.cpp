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
        // M=m;N=n;
        dp.assign(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[0][j]=1;
                dp[i][0]=1;
            }
        }
    //  dp[0][0]=0;
    //  for(int i=1;i<m;i++){
    //     dp[i][0]=1;
    //  }
    //  for(int j=1;j<n;j++){
    //     dp[0][j]=1;
    //  }

for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
}
    return dp[m-1][n-1];    
    }
};