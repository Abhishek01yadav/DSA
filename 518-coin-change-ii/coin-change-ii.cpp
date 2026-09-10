class Solution {
public:
   
   
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long  >> dp(n, vector<long  >(amount+1, 0));
        for (int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] ==0) dp[0][amt] = 1;
            else dp[0][amt]=0;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {

        long   notpick = dp[ind - 1][amt];
                long  pick = 0;
                if (amt >= coins[ind]) {
                    pick = dp[ind][amt-coins[ind]];
                }

               dp[ind][amt] = min((long)INT_MAX, pick + notpick);
            }
        }
        return dp[n-1][amount];
    }
};