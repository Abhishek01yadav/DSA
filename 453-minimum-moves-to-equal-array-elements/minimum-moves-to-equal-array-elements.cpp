class Solution {
public:


    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int moves=0;
         sort(nums.begin(),nums.end());
         for(int i=1;i<n;i++){
            int val=nums[i]-nums[0];
            moves+=val;
         }
        return moves;
        
    }
};