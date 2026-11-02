
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& res) {
        if (!root) {
            res.push_back(INT_MIN);
            return;
        }
        res.push_back(root->val);
        traversal(root->left, res);

        traversal(root->right, res);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> resp, resq;
        traversal(p, resp);
        traversal(q, resq);
        if (resp == resq)
            return true;
        return false;
    }
};