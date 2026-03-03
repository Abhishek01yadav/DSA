class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int temp;
        int ans=0;
        for(int k=0;k<=31;k++){
            temp=1<<k;
            int counto=0;
            for(auto ele:nums){
                if((ele&temp)!=0 )  counto++;
              

            }
            if(counto%3==1)  ans=(ans|temp);
            
        }
        return ans;
        
    }
};