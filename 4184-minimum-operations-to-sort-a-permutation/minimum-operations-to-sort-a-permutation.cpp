class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool asc=true,dsc=true;

        for(int i=1;i<n;i++){
            if(nums[i]!=(nums[i-1]+1)%n) asc=false;
            if(nums[i-1]!=(nums[i]+1)%n) dsc=false;
        }

        if(asc && nums[0]==0){
            return 0;
            
        }

        else if(asc){
            int left_rot=n-nums[0];
            int right_rot=1+(nums.back()+1)+1;
            return min(left_rot,right_rot);
        }
        else if(dsc) {

            int left_rot=n-nums.back()+1;
            int right_rot=(nums.front()+1)%n+1;
            return min(left_rot,right_rot);
            
        }


        
        return -1;
    }
};