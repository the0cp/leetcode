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
class FindElements {
private:
    unordered_map<int,bool>mp;
public:
    void recover(TreeNode* node){
        if(node->left){
            node->left->val=node->val * 2 + 1;
            mp[node->left->val]=true;
            recover(node->left);
        }
        if(node->right){
            node->right->val=node->val * 2 + 2;
            mp[node->right->val]=true;
            recover(node->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        mp[0]=true;
        recover(root);
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
