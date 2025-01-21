class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long ans=LLONG_MAX;
        vector<vector<long long>>pre(2,vector<long long>(n));
        for(int i=n-2; i>=0; i--){
            pre[0][i]=pre[0][i+1]+grid[0][i+1];
        }
        for(int i=1; i<n; i++){
            pre[1][i]=pre[1][i-1]+grid[1][i-1];
        }
        for(int i=0; i<n; i++){
            ans=min(ans, max(pre[0][i], pre[1][i]));
        }
        return ans;
    }
};