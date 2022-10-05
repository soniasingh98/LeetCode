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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *p=new TreeNode();
            p->val=val;
            p->left=root;
            return p;
        }
        queue<TreeNode*>q;
        q.push(root);
        for(int i=0;i<depth-2;i++){
            int size=q.size();
            for(int j=0;j<size;j++){
                TreeNode*n=q.front();
                if(n->left!=NULL)q.push(n->left);
                if(n->right!=NULL)q.push(n->right);
                q.pop();
            }
        }
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode*r=q.front();
           
                TreeNode*ne=new TreeNode();
                ne->val=val;
                ne->left=r->left;
                r->left=ne;
                TreeNode*e=new TreeNode();
                e->val=val;
                e->right=r->right;
                r->right=e;
            q.pop();
        }
        return root;
    }
};