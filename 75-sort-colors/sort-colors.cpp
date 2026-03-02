class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countz=count(nums.begin(),nums.end(),0);
         int counto=count(nums.begin(),nums.end(),1);
        int countt=count(nums.begin(),nums.end(),2);

        int i,j,k;
        for( i=0;i<countz;i++){
            if(nums[i]!=0 ) nums[i]=0;
        }
         for( j=i;j< countz+counto;j++){
            if(nums[j]!=1) nums[j]=1;
        }
         for( k=j;k<nums.size();k++){
            if(nums[k]!=2) nums[k]=2;
        }
        
        
    }
};