class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int n;

    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;

    void lazyAddition(int i, int l, int r, ll val) {
        ll len = r - l + 1;

        // sq must be updated first, because it uses the OLD sum
        sqSumSegTree[i] += 2 * val * sumSegTree[i] + len * val * val;
        sumSegTree[i]   += len * val;
    }

    void updateRange(int start, int end, int i, int l, int r, int val) {
        // 1. apply the pending lazy of this node
        if (lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if (l != r) {
                lazyTree[2 * i + 1] += lazyTree[i];
                lazyTree[2 * i + 2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }

        // 2. out of range
        if (l > end || r < start || l > r) {
            return;
        }

        // 3. completely within range
        if (l >= start && r <= end) {
            lazyAddition(i, l, r, val);

            if (l != r) {
                lazyTree[2 * i + 1] += val;
                lazyTree[2 * i + 2] += val;
            }
            return;
        }

        // 4. partial overlap
        int mid = l + (r - l) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);

        sumSegTree[i]   = sumSegTree[2 * i + 1]   + sumSegTree[2 * i + 2];
        sqSumSegTree[i] = sqSumSegTree[2 * i + 1] + sqSumSegTree[2 * i + 2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqSumSegTree.assign(4 * n, 0);
        sumSegTree.assign(4 * n, 0);
        lazyTree.assign(4 * n, 0);

        unordered_map<int, int> lastIdx;   // value -> last index
        ll result = 0;

        for (int r = 0; r < n; r++) {
            int prev = lastIdx.count(nums[r]) ? lastIdx[nums[r]] : -1;

            // starting points in [prev+1, r] get one new distinct element
            updateRange(prev + 1, r, 0, 0, n - 1, 1);

            // root holds the sum of squares of all subarrays ending at r
            result = (result + sqSumSegTree[0]) % MOD;

            lastIdx[nums[r]] = r;
        }
        return result;
    }
};