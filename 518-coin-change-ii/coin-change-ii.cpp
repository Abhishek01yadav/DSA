class Solution {
public:
int dp[301][5001];
int f(int ind,int amount,vector<int>& coins){
    
    if(ind==0){
        
        
        if( amount % coins[0] ==0) return 1;
        
          return 0;
        
    }
    if(dp[ind][amount] !=-1) return dp[ind][amount];

    int notpick=f(ind-1,amount,coins);
    int pick=0;
    if( amount >= coins[ind]){
        pick=f(ind,amount-coins[ind],coins);
    }

    return  dp[ind][amount]=pick + notpick;

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,amount,coins);
        
    }
};