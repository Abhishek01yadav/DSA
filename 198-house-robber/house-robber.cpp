class Solution {
public:
int dp[101];
int f(int idx,vector<int>& nums){
    if(idx==0) return nums[idx];
    if(idx < 0) return  0;
    if(dp[idx]!=-1) return dp[idx];

    int take=f(idx-2,nums)+nums[idx];
    int skip=f(idx-1,nums);
    int ans = max(skip,take);
    return  dp[idx]=ans;

}
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,nums);

        
    }
};