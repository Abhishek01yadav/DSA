class Solution {
public:
    void nextPermutation(vector<int>& nums ){
       
       // next_permutation(nums.begin(),nums.end());
       //first i have to find breaking point longest matching prefix
       int n=nums.size();
       int idx=-1;
       for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
       }
       if(idx==-1) 
       {reverse(nums.begin(),nums.end());
       return;
       }
       // dusra kaam us idx wale element se just bada element find krna hai.
       for(int i=n-1;i>idx;i--){
        if(nums[i]>nums[idx]){
            swap(nums[i],nums[idx]);
            break;
        }
       }
       // teesra kaam ab sort krna hai idx element k udhar wala part
       reverse(nums.begin()+idx+1,nums.end());
        return;
    }
};