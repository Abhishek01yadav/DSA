class Solution {
public:
set<vector<int>>st;

void f(int idx,vector<int>&ds,vector<int>&nums){
    int n=nums.size();
    if(idx==n){
       
            st.insert(ds);
      
        return;
    }


    //pick 
    int val=nums[idx];
    ds.push_back(val);
    f(idx+1,ds,nums);
    ds.pop_back();

    //not pick
    f(idx+1,ds,nums);
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        sort(nums.begin(),nums.end());
        f(0,ds,nums);
         vector<vector<int>>ans(st.begin(),st.end());
         return ans;
      

        
        
    }
};