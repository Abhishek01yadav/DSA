class Solution {
public:
int dp[105];
int f(int idx,vector<int>& nums){
    if(idx==0) return nums[idx];
    if(idx < 0) return  0;
    if(dp[idx]!=-1) return dp[idx];

    int take=f(idx-2,nums)+nums[idx];
    int skip=f(idx-1,nums);
    int ans = max(skip,take);
    return  dp[idx]=ans;

}

int fbu(int idx,vector<int>& nums){
    if(idx==0) dp[idx]=nums[idx];
    if(idx < 0) dp[idx]=0;
    
    for(int i=1;i<=idx;i++){
        int take=f(idx-2,nums)+nums[idx];
    int skip=f(idx-1,nums);
    int ans = max(skip,take);
     dp[idx]=ans;


    }
    return dp[idx];



}
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fbu(n-1,nums);

        
    }
};