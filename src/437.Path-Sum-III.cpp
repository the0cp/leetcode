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
    vector<int>path;
    int cnt=0;
    int target;
public:
    int pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        dfs(root);
        return cnt;
    }

    void dfs(TreeNode* root){
        if(root==nullptr)   return;
        path.push_back(root->val);
        long sum=0;
        for(int i=path.size()-1; i>=0; i--){
            sum+=path[i];
            if(sum==target)  cnt++;
        }
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
    }
};
