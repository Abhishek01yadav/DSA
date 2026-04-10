
class Solution {
public:

vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
TreeNode* curr=root;
        while(curr!=NULL){
if(curr->left!=NULL){// find the pred
TreeNode*  pred=curr->left;
while(pred->right && pred->right !=curr){
    pred=pred->right;
}
if(pred->right==NULL){//link
pred->right=curr;
curr=curr->left;
}
else{//pred->right=curr:unlink
    pred->right=NULL;
    ans.push_back(curr->val);
    curr=curr->right;

}
}
else{// curr->left==NULL
ans.push_back(curr->val);
curr=curr->right;
}
        }
        return ans;
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int>result;
        result= inorderTraversal(root);
        return result[k-1];

        

        
    }
};