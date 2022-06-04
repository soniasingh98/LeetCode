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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string>a;
       vector<string>b;
        if(preorder(p,a)==preorder(q,b)){
            return true;
        }
        return false;
    }
    vector<string> preorder(TreeNode*root,vector<string>&v){
        if(root==NULL){
            v.push_back("null");
        }
       else{
           string str=to_string(root->val);
            v.push_back(str);
            preorder(root->left,v);
            preorder(root->right,v);
        }
        return v;
    }
};