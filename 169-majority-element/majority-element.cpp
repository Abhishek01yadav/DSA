class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int cnt = 0;
        //boyr moore's voting algorithm
        for (int i = 0; i < n; i++) {

            if (cnt == 0) {
                cnt = 1;
                ele = nums[i];
            }
           else  if (nums[i] == ele)
                cnt++;

            else {
                cnt--;
            }
        }
        return ele;
    }
};