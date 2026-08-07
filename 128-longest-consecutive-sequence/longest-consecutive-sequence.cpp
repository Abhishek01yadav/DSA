class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        
        if(n <=0){
            return 0;
        }

        sort(nums.begin(),nums.end());
        int lastsmaller=INT_MIN;
        int currcnt=1;

        for(int i=0;i<n;i++){

            if(nums[i]-1 == lastsmaller){
                currcnt++;
                lastsmaller=nums[i];
            }

           
            
            else if(nums[i]-1 > lastsmaller){
                currcnt=1;
                lastsmaller=nums[i];
            }

              longest=max(longest,currcnt);
 
        }
       
     
        return longest;

        
    }
};