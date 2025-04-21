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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root)    q.push(root);
        while(!q.empty()){
            TreeNode *rightNode=nullptr;
            int n=q.size();
            while(n-->0){
                TreeNode* node=q.front();
                q.pop();
                if(node){
                    rightNode=node;
                    if(rightNode->left)  q.push(rightNode->left);
                    if(rightNode->right) q.push(rightNode->right);
                }
            }
            if(rightNode)   res.push_back(rightNode->val);
        }
        return res;
    }
};
