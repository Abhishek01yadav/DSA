class Solution {
public:
    const int mod = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);

        for (int x : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (x & (1LL << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long sum = 0;

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 32; bit++) {
                if (cnt[bit] > 0) {
                    x |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            sum = (sum + x * x % mod) % mod;
        }

        return sum;
    }
};