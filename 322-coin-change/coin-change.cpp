class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if (ind == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            }
            return 100005;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int notpick = 0 + f(ind - 1, amount, coins, dp);

        int pick = INT_MAX;
        if (coins[ind] <= amount) {
            pick = 1 + f(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(10001, 0));

        for (int amt = 0; amt<=amount ; amt++) {
            if(amt%coins[0]==0){
                dp[0][amt]=amt/coins[0];
            }

            else dp[0][amt]=INT_MAX;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 1; amt <= amount; amt++) {

                int notpick = 0 + dp[ind - 1][amt] ;

                int pick = 1e9;
                if (coins[ind] <= amt) {
                    pick = 1 + dp[ind][amt-coins[ind]];
                }

                 dp[ind][amt] = min(pick, notpick);
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
    }
};