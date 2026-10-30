
class Solution {
public:

int maxi=INT_MIN;
int height(TreeNode *node){
    if(!node) return 0;
    int lh=height(node->left);
    int  rh=height(node->right);
    return max(lh,rh)+1;


}

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
       
        
        int lh=height(root->left);
        int rh=height(root->right);
        maxi=max(lh+rh,maxi);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);


return maxi;
        
    }
};