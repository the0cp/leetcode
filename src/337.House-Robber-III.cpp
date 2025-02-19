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
    pair<int,int> dfs(TreeNode *node){
        if(node==nullptr)   return {0,0};
        auto [l_rob, l_n_rob]=dfs(node->left);
        auto [r_rob, r_n_rob]=dfs(node->right);
        int rob = l_n_rob + r_n_rob + node->val;
        int n_rob = max(l_rob, l_n_rob) + max(r_rob, r_n_rob);
        return {rob, n_rob};
    }
    int rob(TreeNode* root) {
        auto [rob_root, n_rob_root]=dfs(root);
        return max(rob_root, n_rob_root);
    }
};
