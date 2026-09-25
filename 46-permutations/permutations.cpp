class Solution {
public:
vector<vector<int>>ans;
void f(int idx,vector<int>& nums)
{

int n=nums.size();
    if(idx==n){
        ans.push_back(nums);
        return;
    }



    for(int i=idx;i<n;i++){
        swap(nums[i],nums[idx]);
        
        f(idx+1,nums);

     swap(nums[i],nums[idx]);

    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        f(0,nums);
        return ans;
        

        
    }
};