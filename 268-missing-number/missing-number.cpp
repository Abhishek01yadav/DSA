class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sumofn=n*(n+1)/2;
        int actsum=accumulate(nums.begin(),nums.end(),0);
        return sumofn-actsum;

        
    }
};