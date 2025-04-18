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
    int goodNodes(TreeNode* root, int mx=INT_MIN) {
        if(root==nullptr)   return 0;
        int rcnt=goodNodes(root->right, max(root->val, mx));
        int lcnt=goodNodes(root->left, max(root->val, mx));
        return rcnt+lcnt+(mx<=root->val);
    }
};
