
class Solution {
public:
    void level(TreeNode* root, vector<vector<int>>& ans) {

        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            vector<int> temp;

            for (int i = 0; i < n; i++) {

                auto ele = q.front();
                int x = ele->val;

                q.pop();
                temp.push_back(x);

                if (ele->left != NULL)
                    q.push(ele->left);
                if (ele->right != NULL)
                    q.push(ele->right);
            }

            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        level(root, ans);
        return ans;
    }
};