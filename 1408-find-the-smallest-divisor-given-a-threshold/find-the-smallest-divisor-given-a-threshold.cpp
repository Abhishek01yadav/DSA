class Solution {
public:
int func(vector<int>&nums,int divisor){
    int sumofD=0;

    for(auto ele : nums){
        sumofD += ceil((double)(ele) / (double)(divisor));
    }
   
   
   
   return sumofD;

}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
int res=-1;
        while(low <= high){
            int mid=low+(high-low)/2;

            int ans=func(nums,mid);

            if(ans <= threshold){
                res=mid;
                high=mid-1;

            }
            else {
                low=mid+1;
            }
        }

    return res;
    }
};