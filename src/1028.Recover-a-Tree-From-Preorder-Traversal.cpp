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
    TreeNode* dfs(string cur, int depth){
        int n=cur.size();
        if(n==0)    return nullptr;
        int right=0;
        while(cur[right]>='0'&&cur[right]<='9') right++;
        TreeNode *root=new TreeNode(stoi(cur.substr(0,right)));
        if(right==n)    return root;
        int curDepth=0;
        bool is_right=false;
        for(int i=right; i<n; i++){
            if(cur[i]=='-') curDepth++;
            else{
                if(curDepth==depth&&is_right==false) is_right=true;
                else if(curDepth==depth&&is_right==true){
                    root->left=dfs(cur.substr(right+depth, i-depth-(right+depth)), depth+1);
                    root->right=dfs(cur.substr(i,n-i), depth+1);
                    return root;
                }
                curDepth=0;
            }
        }
        root->left=dfs(cur.substr(right+depth),depth+1);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        return dfs(traversal,1);
    }
};
