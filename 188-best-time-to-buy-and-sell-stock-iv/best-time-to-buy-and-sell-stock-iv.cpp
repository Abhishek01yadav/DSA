class Solution {
public:
int dp[1005][105][5];
int f(vector<int>& prices,int idx,int k,bool on){
    int n=prices.size();
    if(idx==n) return 0;
    int ans=INT_MIN; 
    if(dp[idx][k][on]!=-1 ) return dp[idx][k][on];
    ans=f(prices,idx+1,k,on);///avoid 
    // not avoid
    if(on){
        //sell
        ans=max(ans,prices[idx]+f(prices,idx+1,k-1,false));
    }
    else{
        //buy
        if(k>0){
            ans=max(ans,f(prices,idx+1,k,true)-prices[idx]);

        }
    }

return  dp[idx][k][on]=ans;

}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return f(prices,0,k,false);

        
    }
};