class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int freq=n/3;
        unordered_map<int ,int>mp;
        for(auto ele :nums){
            mp[ele]++;
        }

        for(auto x:mp){
            if(x.second > freq){
                ans.push_back(x.first);
            }

        }

return ans;
        
    }
};