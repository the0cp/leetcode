class Solution {
public:
    void dfs(vector<vector<int>>&isConnected, vector<bool>&visited, int node){
        visited[node]=true;
        for(int i=0; i<visited.size(); i++){
            if(isConnected[node][i]==true&&visited[i]==false){
                dfs(isConnected, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(), 0);
        int cnt=0;
        for(int i=0; i<isConnected.size(); i++){
            if(visited[i]==0){
                dfs(isConnected, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};
