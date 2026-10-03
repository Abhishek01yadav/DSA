
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

 bool ls=   f(root->left,sum,targetSum);
 

 bool  rs=f(root->right,sum,targetSum);


 return ls|| rs;
   
   

}

    bool hasPathSum(TreeNode* root, int targetSum) {
   
      return f(root,0,targetSum);
    
     
        
       
       

        
    }
};