/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isCompleteTree(TreeNode* root) {
         int n=countnodes(root);
         bool ans=checkCBT(root,0,n);
        return ans;
    }
    int countnodes(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int ans=1+countnodes(root->left)+countnodes(root->right);
        return ans;
    }
   bool checkCBT(TreeNode*root,int i,int n){
        if(root==NULL){
            return true;
        }
        else if(i>=n){
            return false;
        }
        else{
            int left=checkCBT(root->left,2*i+1,n);
            int right=checkCBT(root->right,2*i+2,n);
            return(left&&right);
        }
    }
};