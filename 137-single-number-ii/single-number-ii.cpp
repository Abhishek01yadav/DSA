class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int temp;
        int ans=0;
        for(int k=0;k<=31;k++){
            temp=1<<k;
            int countz=0,counto=0;
            for(auto ele:nums){
                if((ele&temp)==0 )  countz++;
                else counto++;

            }
            if(counto%3==1)  ans=(ans|temp);
            
        }
        return ans;
        
    }
};