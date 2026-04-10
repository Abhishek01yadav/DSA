
class Solution {
public:
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     TreeNode* curr = root;
    //     while (curr != NULL) {
    //         if (curr->left != NULL) { /
    //             TreeNode* pred = curr->left;
    //             while (pred->right && pred->right != curr) {
    //                 pred = pred->right;
    //             }
    //             if (pred->right == NULL) { 
    //                 pred->right = curr;
    //                 curr = curr->left;
    //             } else { 
    //                 pred->right = NULL;
    //                 ans.push_back(curr->val);
    //                 curr = curr->right;
    //             }
    //         } else { // curr->left==NULL
    //             ans.push_back(curr->val);
    //             curr = curr->right;
    //         }
    //     }
    //     return ans;
    // }
    vector<int>ans;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);


    }

    int kthSmallest(TreeNode* root, int k) {
        inorder( root);

        
        return ans[k - 1];
    }
};