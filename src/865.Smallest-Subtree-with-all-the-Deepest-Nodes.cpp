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
    TreeNode* dfs(TreeNode* root, int& maxi, int h){
        if(!root)   return nullptr;
        if(maxi==h) return root;
        TreeNode* left=dfs(root->left, maxi, h+1);
        TreeNode* right=dfs(root->right, maxi, h+1);
        if(left&&right) return root;
        return left?left:right;
    }

    int maxDepth(TreeNode* root) {
        if(root==nullptr)   return 0;
        int maxL=maxDepth(root->left);
        int maxR=maxDepth(root->right);
        return 1+max(maxL, maxR);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxi=maxDepth(root)-1;
        return dfs(root, maxi, 0);
    }
};
