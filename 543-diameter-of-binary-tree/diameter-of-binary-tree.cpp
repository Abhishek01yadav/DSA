
class Solution {
public:
int height(TreeNode* root){
    if(root==NULL) return 0;
    int l=height(root->left);
    int r=height(root->right);
     return 1+max(l,r);


}
    int diameterOfBinaryTree(TreeNode* root) {
      
        if(root==NULL) return 0;

        int lh=height(root->left);
        int rh=height(root->right);
     int maxi=lh+rh;

    int l=   diameterOfBinaryTree(root->left);
    int r=   diameterOfBinaryTree(root->right);
       return maxi=max(maxi,max(l,r));










         
        
    }
};