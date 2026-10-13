class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
       for(auto &ele:nums){
        if(ele<0) ele=-1*ele;
       } 
        sort(nums.rbegin(),nums.rend());
        int i=0,j=n-1;
        long long ans=0;
        while(i<=j){
           long long curr=nums[i]*nums[i];
           long long prev=nums[j]*nums[j];

           ans+=abs(curr-prev);
           i++; j--;


        }
        if(n%2!=0){
           long long add=nums[n/2]*nums[n/2];
           ans+=add;
        }
         for(auto ele:nums){
        cout<<ele<<" ";
       }
        
            return ans;
        
      
     
    }
};