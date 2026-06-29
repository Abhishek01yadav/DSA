class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        }
       // tc->o(n2) worst case 
       for (auto ele : nums) {
           if( mp[ele]==1 ) return ele;
        }
       

        return -1;
    }
};