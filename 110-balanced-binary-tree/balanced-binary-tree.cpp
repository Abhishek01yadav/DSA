
class Solution {
public:
int height(TreeNode* root){
    if(root==NULL) return 0;
    int  lh=height(root->left);
    int rh=height(root->right);
    
    return max(lh,rh)+1;

}
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)>1) return false;

        bool left=isBalanced(root->left);
        if(!left) return false;
        bool right=isBalanced(root->right);
        if(!right) return false;

       

        return true;
        
    }
};