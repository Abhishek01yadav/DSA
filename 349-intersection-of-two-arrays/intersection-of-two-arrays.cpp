class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        vector<int> vis(n2, 0);

        for (int i = 0; i < n1; i++) {
            bool already = false;
            for (int x : ans) {
                if (x == nums1[i]) {
                    already = true;
                    break;
                }
            }

            if (already)
                continue;

            for (int j = 0; j < n2; j++) {

                if (nums1[i] == nums2[j] && vis[j] == 0) {

                    ans.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }
            }
        }

        return ans;
    }
};