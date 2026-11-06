class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = queries.size();
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> qs;
        for (int i = 0; i < m; i++) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());

        vector<int> ans(m);
        unordered_map<int,int> freq;
        int L = 0, R = 0, sz = logs.size();

        for (auto& [q, idx] : qs) {
            while (R < sz && logs[R][1] <= q) freq[logs[R++][0]]++;
            while (L < R && logs[L][1] < q - x) {
                if (--freq[logs[L][0]] == 0) freq.erase(logs[L][0]);
                L++;
            }
            ans[idx] = n - freq.size();
        }
        return ans;
    }
};