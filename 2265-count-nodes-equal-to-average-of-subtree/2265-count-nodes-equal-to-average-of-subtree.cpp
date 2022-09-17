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
    int averageOfSubtree(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*p=q.front();
            q.pop();
            vector<int>v;
            int sum=0;
            inorder(p,v);
            for(int i=0;i<v.size();i++){
                sum+=v[i];
            }
            if(sum/v.size()==p->val){
                ans.push_back(p->val);
            }
            if(p->left!=NULL){
                q.push(p->left);
            }
            if(p->right!=NULL){
                q.push(p->right);
            }
        }
        return ans.size();
    }
    void inorder(TreeNode*root,vector<int>&v){
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
};