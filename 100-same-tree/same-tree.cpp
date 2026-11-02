
class Solution {
public:
vector<int>resp;
vector<int>resq;


void traversalq(TreeNode*root){
   if(!root)  {
    resq.push_back(INT_MIN);
    return;
   }
     resq.push_back(root->val);
   traversalq(root->left);
  
  
    traversalq(root->right);


}
void traversalp(TreeNode*root){
   if(!root) {
    resp.push_back(INT_MIN);
    return;
   }
    resp.push_back(root->val);
   traversalp(root->left);
 
  
    traversalp(root->right);


}

    bool isSameTree(TreeNode* p, TreeNode* q) {
        traversalp(p);
        traversalq(q);
        if(resp==resq) return true;
        return false;
        
    }
};