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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>list1, list2;
        dfs(root1, list1);
        dfs(root2, list2);
        return list1==list2;
    }
private:
    void dfs(TreeNode *cur, vector<int>&list){
        if(!cur)    return;
        if(!cur->left&&!cur->right){
            list.push_back(cur->val);
        }
        dfs(cur->left, list);
        dfs(cur->right, list);
    }
};
