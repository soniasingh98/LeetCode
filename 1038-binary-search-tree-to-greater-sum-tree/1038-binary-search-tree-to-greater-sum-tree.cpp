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
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(root,v);
         for(int i=v.size()-2;i>=0;i--){
             v[i]->val+=v[i+1]->val;
         }
        return root;
    }
    void inorder(TreeNode*root,vector<TreeNode*>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
};