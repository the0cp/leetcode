class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans=0;    
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len=q.size();
            vector<int>temp(len);
            for (int i=0; i<len; i++) {
                auto x=q.front();
                q.pop();
                temp[i] = x->val;
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
            pair<int,int>arrpos[len];
            for(int i=0 ;i<len;++i){
                arrpos[i].first = temp[i];
                arrpos[i].second =i;
            }
            sort(arrpos,arrpos+len);
            vector<int>vis(len,0);
            for(int i = 0; i < len;++i){
                int cycle_size = 0;
                if(vis[i]||arrpos[i].second == i){continue;}
                int j = i;
                while(!vis[j]){
                    vis[j] = 1;
                    j = arrpos[j].second;
                    cycle_size+=1;
                }
                if(cycle_size>0)    ans+=(cycle_size-1);
            }           
        }
        return ans;
    }
};
