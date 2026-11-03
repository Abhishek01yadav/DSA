class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //hashing ->precomputing + fetching.
        int n=nums.size();
        vector<int>hash(n+1,0);
        for(auto ele:nums){
            hash[ele]=1;

        }

       for(int i=0;i<hash.size();i++){
        if(hash[i]==0) return i;
       }
       return -1;
        
    }
};