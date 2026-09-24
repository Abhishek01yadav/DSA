class Solution {
public:
vector<vector<int>>ans;

void f(int idx,vector<int>&ds,vector<int>&nums){
    int n=nums.size();
   
   
  

if( ds.size()>=0  )
    {

        ans.push_back(ds);
      
       

    }
    if(idx ==n) return;
  

for(int i=idx;i<n;i++){
    if(i>idx && nums[i]==nums[i-1] ) continue;


   

ds.push_back(nums[i]);
    f(i+1,ds,nums);
    ds.pop_back();
   
   

    
}


  
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        sort(nums.begin(),nums.end());
        f(0,ds,nums);
         
         return ans;
      

        
        
    }
};