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
    vector<TreeNode*>generateTrees(int st, int end){
        vector<TreeNode*>tree;
        if(st>end){
            tree.push_back(NULL);
            return tree;
        }
        for(int i=st; i<=end; i++){
            for(auto leftTree:generateTrees(st,i-1)){    // build left sub tree
                for(auto rightTree:generateTrees(i+1,end)){ // build right sub tree
                    TreeNode *root=new TreeNode(i, leftTree, rightTree);
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1,n);
    }
};
