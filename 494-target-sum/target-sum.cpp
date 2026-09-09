class Solution {
public:

int dp[25][1002];
  int f(int ind,int target,vector<int>& nums){
      if(ind==0){
          if(target==0  && nums[0]==0) return 2;
          if(target==0 || target==nums[0]) return 1;
          
          return 0;
      }
      if(dp[ind][target] !=-1) return dp[ind][target];
      
      int notpick=f(ind-1,target,nums);
      int pick=0;
      if(nums[ind]<=target) pick=f(ind-1,target-nums[ind],nums);
      
      return dp[ind][target]= pick + notpick;
  }
    int findTargetSumWays(vector<int>& nums, int target) {

         int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int tsum=accumulate(nums.begin(),nums.end(),0);
        if(tsum-target <0) return 0;
        if((tsum-target)%2 !=0) return 0;
        int sum=(tsum-target)/2;
        return f(n-1,sum,nums);
        
    }
};