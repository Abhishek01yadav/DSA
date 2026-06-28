class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;

        vector<int> vis(n2, 0);

        for (int i = 0; i < n1; i++) {

            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j] && vis[j] == 0) {
                    ans.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }

                if(nums2[j]>nums1[i]) break;

            } 
        }
        return ans;

            }
        };