class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int res=0;
     
        for(int i=0;i<n;i++){
            set<int>temp;
           temp.insert(nums[i]);
           int c=temp.size();
           res+=(c*c);
            
            for(int j=i+1;j<n;j++)
            {
                temp.insert(nums[j]);
                int c=temp.size();
                res+=(c*c);

            }
            // for(auto &ele: temp){
            //     temp.erase(ele);

            // }
            temp.clear();
        
        }

       
        return res;
    }
};