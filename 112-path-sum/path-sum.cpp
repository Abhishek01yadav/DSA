
class Solution {
public:
bool  f(TreeNode * root ,int sum,int &targetSum){
    if(root==NULL) return false;

    sum+=root->val;
//if we reaches the leaf node;
if(root->left==NULL && root->right==NULL){
    return sum==targetSum;
}

 if(f(root->left,sum,targetSum))  return true;

 

 return f(root->right,sum,targetSum);



   
   

}

    bool hasPathSum(TreeNode* root, int targetSum) {
   
      return f(root,0,targetSum);
    
     
        
       
       

        
    }
};