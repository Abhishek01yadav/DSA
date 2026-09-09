class Solution {
public:
int f(int ind,int amount,vector<int>& coins,vector<vector<int>>&dp){
    
    if(ind==0){
        if(amount % coins[0] ==0 ) {
            return amount/coins[0];
        }
        return 100005;
     }
     if(dp[ind][amount]!=-1) return dp[ind][amount];
    
    int notpick=0+f(ind-1,amount,coins,dp);

    int pick=INT_MAX;
    if(coins[ind]<=amount){
        pick=1+f(ind,amount-coins[ind],coins,dp);
       
    }
    

    return  dp[ind][amount]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(10001,-1));
        int val= f(n-1,amount,coins,dp);
        if(val==100005) return -1;
        return val;
        
    }
};