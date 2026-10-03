
class Solution {
public:
bool  f(TreeNode * root ,int sum,int &targetSum){
    if(root==NULL) return false;

    sum+=root->val;
//if we reaches the leaf node;
if(root->left==NULL && root->right==NULL){
    if(sum==targetSum) return true;
    return false;
}

 int ls=   f(root->left,sum,targetSum);
 int rs=f(root->right,sum,targetSum);


 return ls|| rs;
   
   

}

    bool hasPathSum(TreeNode* root, int targetSum) {
   
      return f(root,0,targetSum);
    
     
        
       
       

        
    }
};