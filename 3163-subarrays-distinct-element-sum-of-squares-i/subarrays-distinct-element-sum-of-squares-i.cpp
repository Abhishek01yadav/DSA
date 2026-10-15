class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int res=0;
     
        for(int i=0;i<n;i++){
            set<int>temp;
           temp.insert(nums[i]);
           res+=(temp.size()*temp.size());
            
            for(int j=i+1;j<n;j++)
            {
                temp.insert(nums[j]);
                res+=(temp.size()*temp.size());

            }
            for(auto &ele: temp){
                temp.erase(ele);

            }
        
        }

       
        return res;
    }
};