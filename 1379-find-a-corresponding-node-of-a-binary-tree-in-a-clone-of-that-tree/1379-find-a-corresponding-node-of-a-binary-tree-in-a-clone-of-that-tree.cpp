/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *p=NULL;
        ansfunc(cloned,target,&p);
        return(p);
    }
    void ansfunc(TreeNode*cloned,TreeNode*target,TreeNode**p){
        if(cloned==NULL)return;
        if(cloned->val==target->val){
           *p=cloned;
            return;
        }
        ansfunc(cloned->left,target,p);
        ansfunc(cloned->right,target,p);
    }
};