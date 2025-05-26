class Solution {
public:
    int dfs(int node, string &colors, vector<vector<int>>&adj, vector<vector<int>>&cnt, vector<int>&vis){
        if(!vis[node]){
            vis[node]=1;
            for(int n:adj[node]){
                if(dfs(n, colors, adj, cnt, vis)==INT_MAX)   return INT_MAX;
                for(int c=0; c<26; c++) cnt[node][c]=max(cnt[node][c], cnt[n][c]);
            }
            cnt[node][colors[node]-'a']++;
            vis[node]=2;
        }
        return vis[node]==2?cnt[node][colors[node]-'a']:INT_MAX;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        vector<vector<int>>cnt(n, vector<int>(26));
        vector<int>vis(n);
        for(auto e:edges)   adj[e[0]].push_back(e[1]);
        int ans=0;
        for(int i=0; i<n; i++)  ans=max(ans, dfs(i, colors, adj, cnt, vis));
        return ans==INT_MAX?-1:ans;
    }
};
