class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntz=0,cnto=0;
        for(auto ele:nums){

            if(ele==0) cntz++;
             if(ele==1) cnto++;
            
        
        }

      
            for(int j=0;j<cntz;j++) nums[j]=0;
             for(int k=cntz;k<(cnto+cntz);k++) nums[k]=1;
              for(int t=cnto+cntz;t<nums.size();t++) nums[t]=2;


     
        
    }
};