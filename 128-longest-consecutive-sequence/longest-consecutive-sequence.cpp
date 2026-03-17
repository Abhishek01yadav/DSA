class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int ele : nums) {
            pq.push(ele);
        }
        int prev = pq.top();
        pq.pop();

        int count = 1, mx = 1;
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            if (curr == prev)
                continue;
            if (curr == prev + 1) {
                count++;
            } else
                count = 1;

            prev = curr;
            mx = max(mx, count);
        }
        return mx;
    }
};