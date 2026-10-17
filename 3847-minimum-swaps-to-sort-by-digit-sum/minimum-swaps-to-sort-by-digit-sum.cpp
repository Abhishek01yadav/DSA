class Solution {
public:
  

    static int sod(int n) {
        int s = 0;
        while (n != 0) {
            s += n % 10;
            n = n / 10;
        }
        return s;
    }
    static bool cmp(int n1, int n2) {

        if (sod(n1) == sod(n2)) {

            return n1 < n2;
        }

        return sod(n1) < sod(n2);
    }

    int minSwaps(vector<int>& nums) {
        vector<int> aftersort(nums);
        int n = nums.size();
        sort(aftersort.begin(), aftersort.end(), cmp);
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int expectedval = aftersort[i];
            int currval = nums[i];
            if (currval == expectedval)
                continue;

            int idx = mp[expectedval];
            nums[i] = expectedval;
            nums[idx] = currval;

            mp[expectedval] = i;
            mp[currval] = idx;
            cnt++;
        }
        return cnt;
    }
};