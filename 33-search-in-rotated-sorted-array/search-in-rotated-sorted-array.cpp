class Solution {
public:
    int findk(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = i + 1;
                break;
            }
        }
        return k;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int k = findk(nums);

        if (k > n)
        {
            k = k % n;
        }

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());

        reverse(nums.begin(), nums.end());

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return (k + mid)%n;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};