class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> prev(n);
        vector<int>dp(n);
        vector<int>result;
        dp[0]=0;
        for(int i=1; i<n; i++){
            prev[i].push_back(i-1);
            dp[i]=i;
        }
        for(auto &query:queries){
            int u = query[0];
            int v = query[1];
            prev[v].push_back(u);
            for(int i=v; i<n; i++){
                for(int e:prev[i]){
                    dp[i]=min(dp[i], dp[e]+1);
                }
            }
            result.push_back(dp[n-1]);
        }
        return result;
    }
};
