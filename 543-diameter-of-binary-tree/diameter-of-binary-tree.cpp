
class Solution {
public:


int height(TreeNode *node,int &val){
    if(!node) return 0;
    int lh=height(node->left,val);
    int  rh=height(node->right,val);
    val=max(lh+rh,val);
    return max(lh,rh)+1;


}

    int diameterOfBinaryTree(TreeNode* root) {
        
       
        int diameter=0;
        height(root,diameter);
        return diameter;
        



        
    }
};