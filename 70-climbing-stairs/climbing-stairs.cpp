class Solution {
public:
int dp[46];
int f(int  idx){
    if(idx ==0 || idx==1) return 1;
    if(dp[idx]!=-1) return dp[idx];
    int left=f(idx-1);
    int right=f(idx-2);
    return dp[idx]=left+right;

  

    
}
    int climbStairs(int n) {
      
         memset(dp,-1,sizeof(dp));
          return f(n);

        
    }
};