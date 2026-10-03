
class Solution {
public:

int height(TreeNode* root,int &maxi){
    if(root==NULL) return 0;
    int l=height(root->left,maxi);
    int r=height(root->right,maxi);
    maxi=max(maxi,l+r);
     return  1+ max(l,r);


}
    int diameterOfBinaryTree(TreeNode* root) {

      int maxi=0;
         height(root,maxi);
         return maxi;




    
        
    }
};