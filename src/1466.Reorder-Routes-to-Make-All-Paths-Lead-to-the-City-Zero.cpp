class Solution {
public:
    int dfs(vector<vector<int>>&g, vector<bool>&visited, int node){
        int cnt=0;
        visited[node]=true;
        for(auto to:g[node]){
            if(!visited[abs(to)]){
                cnt+=dfs(g, visited, abs(to))+(to>0);
            }
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>g(n);
        for(auto&c:connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(-c[0]);
        }
        vector<bool>visited(n);
        return dfs(g, visited, 0);
    }
};
