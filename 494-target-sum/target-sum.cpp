class Solution {
public:
map<pair<int,int>,int>dp;
int f(int ind,int target,vector<int>& nums){
    int cntzero=count(nums.begin(),nums.end(),0);
  
    if(ind==0){
        if(nums[0]==0 && target==0 ) return 2;
        if(target==nums[0] || target==-nums[0]) return 1;
        return 0;
    }

   pair<int,int>state={ind,target};
   if(dp.count(state)) return dp[state];
    int plus=f(ind-1,target-nums[ind],nums);
    int minus=f(ind-1,target+nums[ind],nums);

    
    return  dp[state]=plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       dp.clear();
        return f(n-1,target,nums);
        
        
    }
};