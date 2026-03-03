class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        int n=nums.size();
        int i;
        bool flag=false;
        for(i=1;i<n;i+=3){
            if(nums[i]!=nums[i-1]) {
                flag=true;
                break;
            }
        }
        if(flag){
            ans=nums[i-1];
        }
        else ans=nums[n-1];

      return ans;

    }
};