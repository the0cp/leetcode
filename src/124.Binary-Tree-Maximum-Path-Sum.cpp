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
private:
    int sum=INT_MIN;
public:
    int dfs(TreeNode *node){
        if(node==nullptr)   return 0;
        int lsum=dfs(node->left);
        int rsum=dfs(node->right);
        sum=max(sum, lsum+rsum+node->val);
        return max(max(lsum,rsum)+node->val,0);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
