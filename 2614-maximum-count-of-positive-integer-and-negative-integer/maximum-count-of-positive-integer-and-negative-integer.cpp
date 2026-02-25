class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int mx1=0;
        int mx2=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0) mx1++;
            
            else if(nums[i]>0){
                mx2++;}
            
        }
        return(mx1>=mx2) ? mx1:mx2;
    }
};