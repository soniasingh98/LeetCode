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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            int size=q.size();
            double sum=0;
            for(int i=0;i<size;i++){
                TreeNode*now=q.front();
                q.pop();
                sum+=now->val;
                if(now->left!=NULL){
                    q.push(now->left);
                }
                if(now->right!=NULL){
                    q.push(now->right);
                }
                
               
            }
            double topush=sum/size;
            ans.push_back(topush);
        }
        return ans;
    }
};