class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low=1,high=n-2;
        int cnt=0;

        while(low <= high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }

            else {
                if((mid %2 ==0 && nums[mid]==nums[mid+1])  ||mid %2 !=0  && nums[mid]==nums[mid-1]){
                    //move to the right part 
                    low=mid+1;

                }
                else{//unique phlr khi aa chuka hai iski wajah se sequence gadbad hua hai
                    //move to the left part
                    high=mid-1;

                }
            }
           
             
          
        }
        return -1;  
    }
};