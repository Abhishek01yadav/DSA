class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s(nums1.begin(),nums1.end());
        vector<int>ans;
        for(auto ele:nums2){
            if(s.count(ele)){
                ans.push_back(ele);
                s.erase(ele);
            }
        }
return ans;

        
    }
};