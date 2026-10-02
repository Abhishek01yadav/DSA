
class Solution {
public:
int maxdepth(TreeNode* root){
    if(root==NULL) return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1 + max(lh,rh);
}

    bool isBalanced(TreeNode* root) {
       
      if(root==NULL) return  true;
       int lh=maxdepth(root->left);
       int rh=maxdepth(root->right);
       if(abs(lh-rh) > 1) return false;

       bool left=isBalanced(root->left);
       bool right=isBalanced(root->right);

       if(!left || !right) return false;

       return true;

        
    }
};