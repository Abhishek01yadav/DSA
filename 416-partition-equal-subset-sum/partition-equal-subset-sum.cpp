class Solution {
public:
int dp[201][10004];
  bool f(int ind,int  sum ,vector<int>&nums){
      if(sum==0) return true;
      if(ind==0) return nums[0]==sum;
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      
      bool nottake=f(ind-1,sum,nums);
      bool take=false;
      if(sum >=nums[ind]){
          take=f(ind-1,sum-nums[ind],nums);
      }
      
      return dp[ind][sum]= take or nottake;
  }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tsum=accumulate(nums.begin(),nums.end(),0);
        if(tsum %2 !=0) return false;
        int sum=tsum/2;
        memset(dp,-1,sizeof(dp));
       return   f(n-1,sum,nums);

        
    }
};