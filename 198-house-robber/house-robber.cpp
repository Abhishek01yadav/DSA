class Solution {
public:
vector<int>dp;
int solve(int idx,vector<int>& nums){
    int n=nums.size();
    if(idx<0) return 0;
    if(idx==0 ) return nums[0];
    if(idx==1) return max(nums[0],nums[1]);
    if(dp[idx]!=-1) return dp[idx];
    int a=nums[idx]+solve(idx-2,nums);
   int b= nums[idx-1]+solve(idx-3,nums);
    return  dp[idx]=max(a,b);
}

int solve2(int idx,vector<int>& nums){
    if(idx<0) return 0;
    if(idx==0 ) return nums[0];
    if(idx==1) return max(nums[0],nums[1]);
    if(dp[idx]!=-1) return dp[idx];
    int take=nums[idx]+solve2(idx-2,nums);
   int skip= solve2(idx-1,nums);
    return  dp[idx]=max(skip,take);
}


    int rob(vector<int>& nums) {
        int n=nums.size();
        dp=vector<int>(101,-1);
   
       return  solve2(n-1,nums);

        
    }
};