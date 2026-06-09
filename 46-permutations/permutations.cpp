class Solution {
public:
    void solve(vector<int> ip,
               vector<int> op,
               vector<vector<int>>& ans) {

        if (ip.size() == 0) {
            ans.push_back(op);
            return;
        }

        for (int i = 0; i < ip.size(); i++) {

            vector<int> newip = ip;
            vector<int> newop = op;

            newop.push_back(ip[i]);
            newip.erase(newip.begin() + i);

            solve(newip, newop, ans);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;

        solve(nums, op, ans);
        return ans;
    }
};