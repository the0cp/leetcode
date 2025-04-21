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
    int dfs(TreeNode *root, bool left, int cnt){
        if(root==nullptr)   return cnt;
        if(left)    return max(dfs(root->left, true, 0), dfs(root->right, false, cnt+1));
        return max(dfs(root->right, false, 0), dfs(root->left, true, cnt+1));
    }

    int longestZigZag(TreeNode* root) {
        return max(dfs(root->left, true, 0), dfs(root->right, false, 0));
    }
};
