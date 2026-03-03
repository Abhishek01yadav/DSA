class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int k = 0; k <= n; k++) {
            int temp = __builtin_popcount(k);

            ans[k] = temp;
        }
        return ans;
    }
};