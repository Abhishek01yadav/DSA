class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        }
        auto cmp = [&](int a, int b) { return mp[a] > mp[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto& p : mp) {
            pq.push(p.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};