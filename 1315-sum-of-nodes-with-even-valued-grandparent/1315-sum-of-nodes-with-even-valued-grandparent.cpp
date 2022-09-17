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
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode*p=q.front();
            q.pop();
            if(p->left!=NULL){
                q.push(p->left);
                if((p->left->left!=NULL) && (p->val%2==0)){
                    sum=sum+p->left->left->val;
                }
                if((p->left->right!=NULL) && (p->val%2==0)){
                    sum=sum+p->left->right->val;
                }
            }
            if(p->right!=NULL){
                q.push(p->right);
                if((p->right->left!=NULL) && (p->val%2==0)){
                    sum=sum+p->right->left->val;
                }
                if((p->right->right!=NULL) && (p->val%2==0)){
                    sum=sum+p->right->right->val;
                }
            }
        }
        return sum;
    }
};