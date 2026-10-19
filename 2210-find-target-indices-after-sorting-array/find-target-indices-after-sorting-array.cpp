class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
vector<int>ans;
int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid] <target) low=mid+1;
            else high=mid-1;
        }
        int first=low;

        low=first,high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]<=target) low=mid+1;
            else high=mid-1;


        }
        int last=low;

        for(int i=first;i<last;i++){
            ans.push_back(i);
        }

return ans;
        
    }
};