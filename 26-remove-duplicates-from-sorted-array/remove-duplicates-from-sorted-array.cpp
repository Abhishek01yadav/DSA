class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());

        nums.clear();
        for (auto& ele : st) {
            nums.push_back(ele);
        }

        return nums.size();
    }
};