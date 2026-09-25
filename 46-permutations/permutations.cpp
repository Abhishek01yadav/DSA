class Solution {
public:
vector<vector<int>>ans;
void f(int idx,vector<int>& nums,vector<int>&ds,vector<int>&freq)
{

int n=nums.size();

   if(ds.size()==n){
    ans.push_back(ds);
   }

for(int i=0;i<n;i++){
    if(!freq[i]){
        ds.push_back(nums[i]);
        freq[i]=1;
        f(idx,nums,ds,freq);
        ds.pop_back();
        freq[i]=0;

    }
}


    
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>freq(nums.size(),0);
        vector<int>ds;
        f(0,nums,ds,freq);
        return ans;
        

        
    }
};