
class Solution {
public:

int maxi=0;

int height(TreeNode * root){
    if(root==NULL) return 0;

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right) +1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        maxi=max(maxi,lh+rh) ;

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);



return maxi;
        
    }
};