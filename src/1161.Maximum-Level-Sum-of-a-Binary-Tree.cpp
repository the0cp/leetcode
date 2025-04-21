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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxi=INT_MIN, level=0, ans=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--){
                TreeNode *node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
            if(maxi<sum){
                maxi=sum;
                ans=level;
            }
        }
        return ans;
    }
};
